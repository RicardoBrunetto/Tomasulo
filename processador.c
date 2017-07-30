#include "include/processador.h"

/*Função que simula a estágio de Busca do Pipeline*/
void PIPELINE_fetch(){
  //printf("\n\t\t->>>\tOnFetch!\n");
  if(BUSCA_DECOD_CESSADA) return;
  IR.valor = mem_read(PC.valor); /*Insere a instrução não-decodificada no IR*/
  //printf("IR: %d\n", IR.valor);
  PC.valor = ula(OP_ADD, PC.valor, 4); /*Incrementa PC*/
}

/*Função que simula a estágio de Decodificação do Pipeline
  Pega a instrução [conjunto de Bytes] do IR
  Decodifica a instrução e a insere na fila*/
void PIPELINE_decode(){
  //printf("\n\t\t->>>\tOnDec!\n");
  if(BUSCA_DECOD_CESSADA) return;
  if(IR.valor == FLAG_VAZIO) return;
  int instr = IR.valor; /*Pega o valor que está em IR para decodificar*/
  //printf("IR: %d\n", IR.valor);
  /*Início da Decodificação da Instrução*/
  int opcode = instr >> 26; opcode = opcode & 63;
  int tipo = getTipo_instrucao(opcode); /*Verifica o tipo da Instrução a ser decodificada*/
  Instrucao * instrucao = (Instrucao *)malloc(sizeof(Instrucao));
  instrucao->opcode = opcode;
  int rs, rt, rd, sh, func, target, imm;
  switch(tipo){ /*Se baseia no tipo para separar os campos*/
    case TYPE_R:
      rs = instr >> 21; rs = rs & 31;
      rt = instr >> 16; rt = rt & 31;
      rd = instr >> 11; rd = rd & 31;
      sh = instr >> 6; sh = sh & 31;
      func = instr & 63;
      instrucao->type = TYPE_R;
      instrucao->instruction.instruction_R.rs = rs;
      instrucao->instruction.instruction_R.rt = rt;
      instrucao->instruction.instruction_R.rd = rd;
      instrucao->instruction.instruction_R.shift = sh;
      instrucao->instruction.instruction_R.func = func;
      break;
    case TYPE_J:
      target = instr << 6; target = target >> 6;
      instrucao->type = TYPE_J;
      instrucao->instruction.instruction_J.target= target;
      break;
    case TYPE_I:
      rs = instr >> 21; rs = rs & 31;
      rt = instr >> 16; rt = rt & 31;
      imm = instr << 16; imm = imm >> 16;
      instrucao->type = TYPE_I;
      instrucao->instruction.instruction_I.rs = rs;
      instrucao->instruction.instruction_I.rt = rt;
      int msb = imm >> 15;
      if(msb)
        imm = imm | 4294901760;
      instrucao->instruction.instruction_I.imm = imm;
      break;
  }

  /*Fim da Decodificação da Instrução*/
  if(instrucao->type == TYPE_J){ /*Caso for uma instrução de desvio incondicional (todas do tipo J são)*/
    if(instrucao->opcode == 3) /*jal*/
      inserir_no_barramento(CDB, PC.valor, FLAG_VAZIO, REG_RA); /*Escreve PC atual (incrementado após decodificar o jump)*/
    PC.valor = instrucao->instruction.instruction_J.target; /*PC recebe o endereço alvo da instrução*/
    limpar_fila_instrucoes();
    IR.valor = FLAG_VAZIO;
  }else{
    if(is_cessar_busca_decode(instrucao)) /*branches*/ BUSCA_DECOD_CESSADA = 1; /*Cessa a busca e a decodificação - para manter NPC*/
    inserir_fila(&fila_Instrucoes, instrucao); /*Insere a instrução na Fila de Instruções*/
    /*mostrar_fila(&fila_Instrucoes);*/
  }
}

void PIPELINE_issue(){
  //printf("\n\t\t->>>\tOnIssue\n");
  if(EMISSAO_CESSADA) return; /*Não emite*/
  int i, aux;
  Instrucao * instr = (Instrucao *) get_topo_fila(&fila_Instrucoes); /*Pega uma instrução da fila (mas não a remove de lá)*/
  if(instr == NULL) return; /*Não há mais instruções na fila*/
  /*printf("\nEmitindo: ");
  printar_instr(instr);*/
  for(i = 0; i<QUANTIDADE_ESTACOES_RESERVA; i++){
    //printf("\nAnalisando ER %i\n", i);
    if(estacoes_Reserva[i].BusyBit != FLAG_DISPONIVEL){ /*printf("Nao serve\n");*/ continue; }/*Pula se a Estação de Reserva estiver ocupada*/
    //printf("Serve!!\n");
    if(instr->type == TYPE_I)
      aux = instr->opcode == 1 ? get_abstract_opcode(instr->opcode, instr->instruction.instruction_I.rt) : instr->opcode; /*Instruções de opcode 1 têm o function no rt (branches)*/
    else if(instr->type == TYPE_R)
      aux = get_abstract_opcode(instr->opcode, instr->instruction.instruction_R.func);

    /*Antes da emissão, de fato, ocorre a verificação, se aquela ER possui uma Unidade Funcional capaz de processá-la*/
    if(is_uf_compativel(aux, estacoes_Reserva[i].uf.type)){ /*Se aquela Unidade Funcional puder processar a instrução*/
      /*EMISSÃO*/
      estacoes_Reserva[i].BusyBit = get_ciclos(aux);
      estacoes_Reserva[i].Op = aux;
      //printf("\nToremove\n");
      instr = (Instrucao *) remover_fila(&fila_Instrucoes); /*Não altera instr, apenas a remove da fila de fato, emitindo-a de fato*/
          /*Para instruções do tipo R*/
      if(instr->type == TYPE_R){ /*Caso seja do tipo R*/
        /*Verifica se deve cessar a emissão*/
        if(is_cessar_emissao(estacoes_Reserva[i].Op)) EMISSAO_CESSADA = 1;
        /*Emite a instrução do tipo R*/
        if((estacoes_Reserva[i].Qj = reg_get_status(instr->instruction.instruction_R.rs)) == FLAG_DISPONIVEL){ /*Leitura do operando em VJ (rs)*/
          estacoes_Reserva[i].Vj = reg_read(instr->instruction.instruction_R.rs);
        }
        if((estacoes_Reserva[i].Qk = reg_get_status(instr->instruction.instruction_R.rt)) == FLAG_DISPONIVEL){ /*Leitura do operando em VK (rt)*/
          estacoes_Reserva[i].Vk = reg_read(instr->instruction.instruction_R.rt);
        }
        estacoes_Reserva[i].A = instr->instruction.instruction_R.shift;
        reg_change_status(instr->instruction.instruction_R.rd, i); /*Renomeia o registrador de destino*/
      /*Para instruções do tipo I*/
      }else if(instr->type == TYPE_I){
        /*Verifica se deve cessar a emissão*/
        if(is_cessar_emissao(estacoes_Reserva[i].Op)) EMISSAO_CESSADA = 1;
        /*Executa o algoritmo*/
        if((estacoes_Reserva[i].Qj = reg_get_status(instr->instruction.instruction_I.rs)) == FLAG_DISPONIVEL){ /*Leitura do operando em VJ*/
          estacoes_Reserva[i].Vj = reg_read(instr->instruction.instruction_I.rs);
        }
        estacoes_Reserva[i].A = instr->instruction.instruction_I.imm;
        /*Loads e Stores são do Tipo I e possuem emissão diferenciada*/
        if(is_rt_destino(estacoes_Reserva[i].Op)){ /*Verifica se a instrução é um load ou alguma que requeira rt como destino*/
          reg_change_status(instr->instruction.instruction_I.rt, i);
        }else if(is_rt_operando(estacoes_Reserva[i].Op)){ /*Verifica se a instrução é um store ou ou alguma que requeira rt como operando*/
          if((estacoes_Reserva[i].Qk = reg_get_status(instr->instruction.instruction_I.rt)) == FLAG_DISPONIVEL){ /*Leitura do operando em VK*/
            estacoes_Reserva[i].Vk = reg_read(instr->instruction.instruction_I.rt);
          }
        }else if(is_writter_branch(estacoes_Reserva[i].Op)){ /*Alguns branches escrevem no registrador 31*/
          reg_change_status(REG_RA, i);
        }
      } /*Instruções do tipo J são verificadas na decodificação*/
      break;
    }
  }
}

/*Função que simula a estágio de Execução do Pipeline
  Para cada Estação de Reserva livre que for do tipo da primeira instrução da fila naquele instante
  Colocar-se-á a instrução para executar
  Caso a instrução já esteja ocupada, diminui-se a quantidade de ciclos restantes*/
void PIPELINE_execute(){
  //printf("\n\t\t->>>\tOnExec!\n");
  int i, aval = 0;
  for(i = 0; i<QUANTIDADE_ESTACOES_RESERVA; i++){
    if(estacoes_Reserva[i].BusyBit > 0){  /*Se a ER estiver ocupada*/
      if(is_cessar_emissao(estacoes_Reserva[i].Op)) EMISSAO_CESSADA++; /*Garante que a emissão continua cessada enquanto a instrução está no Pipeline*/
      if(estacoes_Reserva[i].Qj == FLAG_DISPONIVEL && estacoes_Reserva[i].Qk == FLAG_DISPONIVEL){ /*verifica operadores: já estiverem prontos, os ciclos contam*/
        //printf("\n\t\tOp disponiveis");
        /*Caso for um Load ou um Store*/
        if(isLoad(estacoes_Reserva[i].Op) || isStore(estacoes_Reserva[i].Op)){
          if(estacoes_Reserva[i].BusyBit == 3){
              Dado_Barramento * db = topo_barramento(PCB);
              if(db->controle == FLAG_READY){
                if(PCB.status == i){
                  /*Escreve o dado lido no buffer da Unidade Funcional*/
                  estacoes_Reserva[i].uf.ALUOutput = filtrar_dado(estacoes_Reserva[i].Op, db->dado); /*O filtro serve para casos onde não é a palavra toda a ser carregada*/
                  enviar_para_CDB(i); /*Escreve *no CDB*/
                  estacoes_Reserva[i].BusyBit = FLAG_DISPONIVEL;
                  /*Torna PCB disponível*/
                  PCB.status = FLAG_READY;
                  alterar_topo_barramento(PCB, FLAG_VAZIO, FLAG_VAZIO, FLAG_READY);
                }else if(PCB.status == FLAG_READY){ /*controle = READY e status = READY => PCB está disponível*/
                  er_despachar(i); /*Despacha o Load ou o Store*/
                }
              }
          }else{
            estacoes_Reserva[i].BusyBit = estacoes_Reserva[i].BusyBit - 1;
          }
        /*Caso não for um load/store*/
        }else{
          //printf("\nNot load nem store\n");
          estacoes_Reserva[i].BusyBit = estacoes_Reserva[i].BusyBit - 1; /*decrementa a quantidade de ciclos restantes*/
          if(estacoes_Reserva[i].BusyBit == 1){
            if(is_escrever_hi_lo(estacoes_Reserva[i].Op)){
              estacoes_Reserva[i].A = REG_HI;
              er_despachar(i); /*Despacha a primeira parte da instrução (escreve no hi e lo em 2 ciclos)*/
            }
          }else if(estacoes_Reserva[i].BusyBit == 0){/*Último ciclo de clock da instrução*/
            if(is_escrever_hi_lo(estacoes_Reserva[i].Op)) estacoes_Reserva[i].A = REG_LO; /*Informa para escrever em LO no segundo ciclo*/
            /*Segura syscall com exit até o fim da execução*/
            if(!(estacoes_Reserva[i].Op == 291 && estacoes_Reserva[i].Vj == FLAG_EXIT))
              er_despachar(i); /*Despacha para execução (é instantânea) e escreve no CDB - Load/Store já foi despachado*/
          }
        }
      }
    }else{
      aval++;
    }
  }
  /*Despacha a exit*/
  if(aval == QUANTIDADE_ESTACOES_RESERVA - 1){
    for(i = 0; i<QUANTIDADE_ESTACOES_RESERVA; i++){
      if(estacoes_Reserva[i].Op == 291){
        if(estacoes_Reserva[i].Vj == FLAG_EXIT)
        er_despachar(i);
      }
    }
  }
}

/*Função que simula a estágio de Escrita do Pipeline
  Obtém o resultado que está no CDB
  Atualiza as ER's e o Banco de Registradores*/
void PIPELINE_write(){
   /*O campo endereco do CDB contém o índice da Estação de Reserva que gerou o dado*/
  Dado_Barramento * conteudo;
  if((conteudo = get_topo_barramento(CDB)) == NULL) return; /*Indica que nada foi escrito no CDB ainda (nada foi executado)*/
  /*Se a instrução manipula HI/LO, então eles são escritos*/
  if(conteudo->controle == REG_RA){ reg_write(conteudo->dado, REG_RA); return; }
  if(conteudo->controle == REG_HI){ reg_write(conteudo->dado, REG_HI); return; }
  if(conteudo->controle == REG_LO){ reg_write(conteudo->dado, REG_LO); BUSCA_DECOD_CESSADA = 0; estacoes_Reserva[conteudo->endereco].BusyBit = FLAG_DISPONIVEL;  estacoes_Reserva[conteudo->endereco].A = FLAG_VAZIO;/*Permite a busca e decodificação*/ return; }
  int i;
  if(is_conditionalMove(estacoes_Reserva[conteudo->endereco].Op)){
    if(conteudo->controle == 0){
      for(i=1; i<(sizeof(banco_Registradores)/sizeof(Registrador)); i++){ /*Ignora o registrador ZERO*/
        if(reg_get_status(i) == conteudo->endereco){ /*Caso Qi do registrador seja igual ao índice da Estação de Reserva*/
            break;
        }
      }
      conteudo->dado = reg_read(i);
    }
  }
  /*Verifica as Estações de Reserva que estão agurdando o dado*/
  for(i=0; i<QUANTIDADE_ESTACOES_RESERVA; i++){
    if(estacoes_Reserva[i].Qj == conteudo->endereco){
      estacoes_Reserva[i].Qj = FLAG_DISPONIVEL;
      estacoes_Reserva[i].Vj = conteudo->dado;
    }
    if(estacoes_Reserva[i].Qk == conteudo->endereco){
      estacoes_Reserva[i].Qk = FLAG_DISPONIVEL;
      estacoes_Reserva[i].Vk = conteudo->dado;
    }
  }
  /*Verifica os registradores que estão aguardando o dado*/
  for(i=1; i<(sizeof(banco_Registradores)/sizeof(Registrador)); i++){ /*Ignora o registrador ZERO*/
    if(reg_get_status(i) == conteudo->endereco){ /*Caso Qi do registrador seja igual ao índice da Estação de Reserva*/
      reg_change_status(i, FLAG_DISPONIVEL); /*Muda o Qi do registrador para indicar que está disponível*/
      reg_write(conteudo->dado, i); /*Escreve o dado no registrador*/
    }
  }
  estacoes_Reserva[conteudo->endereco].BusyBit = FLAG_DISPONIVEL;
}


void processador_print(){
  //cache_print();
  reg_banco_print();
  er_print();
}

/*Procedimento que inicializa os componentes do processador*/
void processador_start(){
  inicializar_fila(&fila_Instrucoes);
  inicializar_barramentos();
  inicializar_registradores();
  inicializar_estacoes_reserva();
  reg_write(MEM_SIZE, REG_PS);
  reg_write(START_ADDRESS_DATA, REG_PG);
  PC.valor = 0;
  IR.valor = FLAG_VAZIO;
  EMISSAO_CESSADA = 0;
  BUSCA_DECOD_CESSADA = 0;
}

/*Procedimento que atua como clock do processador*/
void processador_next(){
  EMISSAO_CESSADA = 0;
  PIPELINE_write();
  PIPELINE_execute();
  PIPELINE_issue();
  PIPELINE_decode();
  PIPELINE_fetch();
}

/*int main(){
  processador_start();


  Instrucao * i = (Instrucao *) malloc(sizeof(Instrucao));
  i->type = TYPE_J;
  i->instruction.instruction_J.opcode = 12;
  inserir_fila(&fila_Instrucoes, i);
  i = remover_fila(&fila_Instrucoes);
  //printf("\n\t->[%d]\n", i->instruction.instruction_J.opcode);
  processador_print();
}*/
