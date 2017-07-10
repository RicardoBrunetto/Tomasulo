#include "processador.h"

#include <string.h>

/*Função que simula a estágio de Busca do Pipeline*/
void PIPELINE_fetch(){
  IR.valor = mem_read(PC.valor); /*Insere a instrução não-decodificada no IR*/
  PC.valor = PC.valor + 4; /*Incrementa PC*/
}

/*Função que simula a estágio de Decodificação do Pipeline
  Pega a instrução [conjunto de Bytes] do IR
  Decodifica a instrução e a insere na fila*/
void PIPELINE_decode(){
  int instr = IR.valor /*Pega o valor que está em IR para decodificar*/
  /*Início da Decodificação da Instrução*/
  int opcode = instr >> 26; opcode = opcode & 63;
  int tipo = getTipo_instrucao(opcode); /*Verifica o tipo da Instrução a ser decodificada*/
  Instrucao * instrucao = (Instrucao *)malloc(sizeof(Instrucao));
  switch(tipo){ /*Se baseia no tipo para separar os campos*/
    case TYPE_R:
      int rs = instr >> 21; rs = rs & 31;
      int rt = instr >> 16; rt = rt & 31;
      int rd = instr >> 11; rd = rd & 31;
      int sh = instr >> 6; sh = sh & 31;
      int func = instr & 63;
      Instrucao->type = TYPE_R;
      Instrucao->instruction_R->opcode = opcode;
      Instrucao->instruction_R->rs = rs;
      Instrucao->instruction_R->rt = rt;
      Instrucao->instruction_R->rd = rd;
      Instrucao->instruction_R->shift = sh;
      Instrucao->instruction_R->func = func;
      break;
    case TYPE_J:
      int target = target << 6; target = target >> 6;
      Instrucao->type = TYPE_J;
      Instrucao->instruction_J->opcode = opcode;
      Instrucao->instruction_J->target = target;
      break;
    case TYPE_I:
      int rs = instr >> 21; rs = rs & 31;
      int rt = instr >> 16; rt = rt & 31;
      int imm = instr << 16; imm = imm >> 16;
      Instrucao->type = TYPE_I;
      Instrucao->instruction_I->opcode = opcode;
      Instrucao->instruction_I->rs= rs;
      Instrucao->instruction_I->rt = rt;
      Instrucao->instruction_I->imm = imm;
      break;
  }
  /*Fim da Decodificação da Instrução*/
  if(isInconditionalJump(i)){ /*Caso for uma instrução de desvio incondicional*/
    PC.valor = i->instruction.instruction_J.target; /*PC recebe o endereço alvo da instrução*/
  }else{
    inserir_fila(&fila_Instrucoes, i); /*Insere a instrução na Fila de Instruções*/
  }
}

/*Função que simula a estágio de Execução do Pipeline
  Para cada Estação de Reserva livre que for do tipo da primeira instrução da fila naquele instante
  Colocar-se-á a instrução para executar
  Caso a instrução já esteja ocupada, diminui-se a quantidade de ciclos restantes*/
void PIPELINE_execute(){
  int i, estacoes_ocupadas = 0;
  for(i = 0; i<QUANTIDADE_ESTACOES_RESERVA; i++){
    if(estacoes_Reserva[i].BusyBit > 0){  // Se a ER estiver ocupada
      estacoes_Reserva[i].BusyBit = estacoes_Reserva[i].BusyBit - 1; // decrementa a quantidade de ciclos restantes
      estacoes_ocupadas++; // controla a quantidade de ER's ocupadas
    }else{ // Estação de Reserva Disponível
      Instrucao * instr = get_topo_fila(&fila_Instrucoes); // Pega uma instrução da fila (mas não a remove de lá)
      // Antes da emissão, de fato, ocorre a verificação, se aquela ER possui uma Unidade Funcional capaz de processá-la
      if(instr == NULL) continue; // Não há mais instruções na fila, passa para a próxima ER
      if(tipo_compativel(instr->type, estacoes_Reserva[i].uf.type)){ // Se aquela Unidade Funcional puder processar a instrução
        instr = remover_fila(&fila_Instrucoes); // Não altera instr, apenas a remove da fila de fato, emitindo-a

        estacoes_ocupadas++;
      }else{  // Se não puder, analisa a próxima ER
        continue;
      } // Analisa a próxima estação de Reserva
    //  estacoes_Reserva[i].BusyBit =
    }
  }
  if(!estacoes_ocupadas && (get_topo_fila(&fila_Instrucoes) == NULL)){ //Se nenhuma Estacao estiver ocupada e não houver mais instruções na fila
    printf("\nFim de execução\n");
  }
}

/*Função que simula a estágio de Escrita do Pipeline
  Obtém o resultado que está no CDB
  Atualiza as ER's e o Banco de Registradores*/
void PIPELINE_write(){

}


void processador_print(){
  //cache_print();
  reg_banco_print();
  er_print();
}


/*Procedimento que inicializa os componentes do processador*/
void processador_start(){
  inicializar_fila(&fila_Instrucoes);
  inicializar_registradores();
  inicializar_estacoes_reserva();
  PC.valor = 0;
}

/*Procedimento que atua como clock do processador*/
void processador_next(){
  PIPELINE_write();
  PIPELINE_execute();
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
  printf("\n\t->[%d]\n", i->instruction.instruction_J.opcode);
  mostrar_fila(&fila_Instrucoes);

  processador_print();
}*/
