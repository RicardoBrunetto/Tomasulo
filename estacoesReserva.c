#include "include/estacoesReserva.h"

void inicializar_estacoes_reserva(){
  //QUANTIDADE_ESTACOES_RESERVA = QUANTIDADE_ESTACOES_RESERVA_ADD + QUANTIDADE_ESTACOES_RESERVA_MUL + QUANTIDADE_ESTACOES_RESERVA_LOAD + QUANTIDADE_ESTACOES_RESERVA_STORE;
  estacoes_Reserva = (EstacaoReserva *) malloc(sizeof(EstacaoReserva)*QUANTIDADE_ESTACOES_RESERVA);
  int i;
  for(i=0; i<QUANTIDADE_ESTACOES_RESERVA; i++){
    estacoes_Reserva[i].Qj = FLAG_DISPONIVEL;
    estacoes_Reserva[i].Qk = FLAG_DISPONIVEL;
    estacoes_Reserva[i].BusyBit = FLAG_DISPONIVEL;
    if(QUANTIDADE_ESTACOES_RESERVA_ADD > i){
      estacoes_Reserva[i].uf.type = ADD_UF;
    }else if(QUANTIDADE_ESTACOES_RESERVA_ADD + QUANTIDADE_ESTACOES_RESERVA_MUL > i){
      estacoes_Reserva[i].uf.type = MUL_UF;
    }else if(QUANTIDADE_ESTACOES_RESERVA_ADD + QUANTIDADE_ESTACOES_RESERVA_MUL + QUANTIDADE_ESTACOES_RESERVA_LOAD > i){
      estacoes_Reserva[i].uf.type = LOAD_UF;
    }else{
      estacoes_Reserva[i].uf.type = STORE_UF;
    }
  }
}

void clear_station(int i){
  estacoes_Reserva[i].Qj = FLAG_DISPONIVEL;
  estacoes_Reserva[i].Vj = FLAG_DISPONIVEL;
  estacoes_Reserva[i].Qk = FLAG_DISPONIVEL;
  estacoes_Reserva[i].Vk = FLAG_DISPONIVEL;
  estacoes_Reserva[i].A = FLAG_DISPONIVEL;
  estacoes_Reserva[i].BusyBit = FLAG_DISPONIVEL;
}

void enviar_para_CDB(int indice_ER){
  Dado_Barramento * d = (Dado_Barramento *) malloc(sizeof(Dado_Barramento));
  d->endereco = indice_ER;
  d->dado = estacoes_Reserva[indice_ER].uf.ALUOutput;
  /*Verifica se o escreve no HI ou no LO*/
  if(is_escrever_hi_lo(estacoes_Reserva[indice_ER].Op)){
    /*Se escrever então informa, no barramento, em qual registrador (HI/LO) escrever*/
    d->controle = estacoes_Reserva[indice_ER].A;
  }else{
    d->controle = FLAG_VAZIO;
  }
  if(is_conditionalMove(estacoes_Reserva[indice_ER].Op))
    d->controle = estacoes_Reserva[indice_ER].A;

  if(is_branch(estacoes_Reserva[indice_ER].Op)){
    if(d->dado == BRANCH_TAKEN){
      d->dado = PC.valor; /*o atual de PC vai para o barramento (se o branch tiver efeito de escrita, ele sempre escreverá o valor da próxima instrução)*/
      PC.valor = estacoes_Reserva[indice_ER].A; /*PC recebe o imediato*/
      limpar_fila_instrucoes();
      IR.valor = FLAG_VAZIO;
    }else{
      d->dado = reg_read(REG_RA); /*escreve o atual valor de RA em RA*/
    }
    BUSCA_DECOD_CESSADA = 0; /*Permite a busca e decodificação*/
  }
  /*printf("\ninserido no barramento: dado %d e endereco %d\n", d->dado, d->endereco);*/
  inserir_Dado_no_Barramento(CDB, d);
}

/*Procedimento que envia a instrução para a Unidade Funcional*/
void er_despachar(int indice_ER){
  /*printf("\nDESPACHANDO DE %d => OP = %d\n", indice_ER, estacoes_Reserva[indice_ER].Op);*/
  /*Apenas para tornar o código mais legível*/
  int Vk = estacoes_Reserva[indice_ER].Vk;
  int Vj = estacoes_Reserva[indice_ER].Vj;
  int A = estacoes_Reserva[indice_ER].A;
  int aux; /*Registrador auxiliar interno*/
  /*Verifica o que fazer com a instrução de acordo com o opcode*/
  switch(estacoes_Reserva[indice_ER].Op){
    case 252:		/*add*/
    case 253:		/*addu*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_ADD, Vj, Vk);
    	break;

    case 8:		/*addi*/
    case 9:		/*addiu*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_ADD, Vj, A);
    	break;

    case 274:		/*sub*/
    case 275:		/*subu*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_SUB, Vj, Vk);
    	break;

    case 254:		/*and*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_AND, Vj, Vk);
    	break;

    case 12:		/*andi*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_AND, Vj, A);
    	break;

    case 266:		/*nor*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_NOR, Vj, Vk);
    	break;

    case 267:		/*or*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_OR, Vj, Vk);
    	break;

    case 13:		/*ori*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_OR, Vj, A);
    	break;

    case 276:		/*xor*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_XOR, Vj, Vk);
    	break;

    case 14:		/*xori*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_ADD, Vj, A);
    	break;

    case 268:		/*sll*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_SLL, Vk, A);
    	break;

    case 269:		/*sllv*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_SLL, Vk, Vj);
    	break;

    case 270:		/*sra*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_SRA, Vk, A);
    	break;

    case 271:		/*srav*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_SRA, Vk, Vj);
    	break;

    case 272:		/*srl*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_SRL, Vk, A);
    	break;

    case 273:		/*srlv*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_SRL, Vk, Vj);
    	break;

    case 255:		/*clo*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = __builtin_clz(~Vj);
    	break;

    case 256:		/*clz*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = __builtin_clz(Vj);
    	break;

    case 257:		/*div*/
    case 258:		/*divu*/
      if(A == REG_HI)
        estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_MOD, Vj, Vk);
      else if(A == REG_LO)
        estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_DIV, Vj, Vk);
    	break;

    case 259:		/*mult*/
      if(A == REG_HI){
        estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_MULuHI, Vj, Vk);
      }else if(A == REG_LO)
        estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_MULu, Vj, Vk);
      break;

    case 260:		/*multu*/
      if(A == REG_HI)
        estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_MULsHI, Vj, Vk);
      else if(A == REG_LO)
        estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_MULs, Vj, Vk);
      break;

    case 261:		/*mul*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_MULs, Vj, Vk);
    	break;

    case 277:		/*slt*/
    case 278:		/*sltu*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_AmeB, Vj, Vk);
    	break;

    case 10:		/*slti*/
    case 11:		/*sltiu*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_AmeB, Vj, A);
    	break;

    case 289:		/*movn*/
      estacoes_Reserva[indice_ER].A = !ula(OP_AeqB, Vk, 0);
      estacoes_Reserva[indice_ER].uf.ALUOutput = Vj;
    	break;

    case 290:		/*movz*/
      estacoes_Reserva[indice_ER].A = ula(OP_AeqB, Vk, 0);
      estacoes_Reserva[indice_ER].uf.ALUOutput = Vj;
    	break;

    case 4:		/*beq*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_AeqB, Vj, Vk) == 1 ? BRANCH_TAKEN : BRANCH_NOT_TAKEN;
    	break;

    case 279:		/*bgez*/
    case 280:		/*bgezal*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_OR, ula(OP_AmaB, Vj, 0), ula(OP_AeqB, Vj, 0)) == 1 ? BRANCH_TAKEN : BRANCH_NOT_TAKEN;
    	break;

    case 7:		/*bgtz*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_AmaB, Vj, 0) == 1 ? BRANCH_TAKEN : BRANCH_NOT_TAKEN;
    	break;

    case 6:		/*blez*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_OR, ula(OP_AmeB, Vj, 0), ula(OP_AeqB, Vj, 0)) == 1 ? BRANCH_TAKEN : BRANCH_NOT_TAKEN;
    	break;

    case 281:		/*bltzal*/
    case 282:		/*bltz*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_AmeB, Vj, 0) == 1 ? BRANCH_TAKEN : BRANCH_NOT_TAKEN;
    	break;

    case 5:		/*bne*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_AeqB, Vj, Vk) == 0 ? BRANCH_TAKEN : BRANCH_NOT_TAKEN;
    	break;

    case 283:		/*jalr*/
    case 284:		/*jr*/
      estacoes_Reserva[indice_ER].A = Vj;
      estacoes_Reserva[indice_ER].uf.ALUOutput = BRANCH_TAKEN;
    	break;

    case 15:		/*lui*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = ula(OP_SLL, A, 16);
    	break;

    case 59:   /*li*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = A;
      break;

    case 52:   /*move*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = Vj;
      break;

    case 32:		/*lb*/
    case 36:		/*lbu*/
    case 33:		/*lh*/
    case 37:		/*lhu*/
    case 35:		/*lw*/
    case 34:		/*lwl*/
    case 38:		/*lwr*/
      PCB.status = indice_ER;
      alterar_topo_barramento(PCB, FLAG_VAZIO, ula(OP_ADD, Vj, A), FLAG_READ); /*Ler da cache o endereço VJ + A (offset + rs)*/
    	break;

    case 40:		/*sb*/
    case 41:		/*sh*/
    case 42:		/*swl*/
    case 43:    /*sw*/
    case 46:		/*swr*/
      PCB.status = indice_ER;
      alterar_topo_barramento(PCB, filtrar_dado(estacoes_Reserva[indice_ER].Op, Vk), ula(OP_ADD, Vj, A), FLAG_WRITE); /*Ler da cache o endereço VJ + A (offset + rs)*/
    	break;

    case 285:		/*mfhi*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = reg_read(REG_HI); /*Certamente, não há ninguém manipulando HI*/
    	break;

    case 286:		/*mflo*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = reg_read(REG_LO); /*Certamente, não há ninguém manipulando LO*/
    	break;

    case 287:		/*mthi*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = Vj;
    	break;

    case 288:		/*mtlo*/
      estacoes_Reserva[indice_ER].uf.ALUOutput = Vj;
    	break;

    case 291:		/*syscall*/
      if(ula(OP_AeqB, Vj, FLAG_EXIT))
        clock_finish();
      else{
        estacoes_Reserva[indice_ER].BusyBit = FLAG_DISPONIVEL;
        RETURN_VAL = Vk;
      }
    	break;

    case 292:		/*nop*/
    	break;
  }
  if(!isLoad(estacoes_Reserva[indice_ER].Op) && !isStore(estacoes_Reserva[indice_ER].Op))
    enviar_para_CDB(indice_ER);
}

void er_print(){
  int indice_ER;
  printf("\n\tESTAÇÕES DE RESERVA\n");
  printf("*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
  printf("*\tIndice\t|\tTipo\t|\tBusyBit\t|\t\tOp\t|\tQj\t|\t\tVj\t|\tQk\t|\t\tVk\t|\t\t a\t*\n");
  printf("*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
  for(indice_ER = 0; indice_ER<QUANTIDADE_ESTACOES_RESERVA; indice_ER++){
    printf("*\t%2d\t|\t", indice_ER);
    switch (estacoes_Reserva[indice_ER].uf.type) {
      case ADD_UF:
        printf("ADD");
        break;
      case MUL_UF:
        printf("MUL");
        break;
      case LOAD_UF:
        printf("LOAD");
        break;
      case STORE_UF:
        printf("STORE");
        break;
    }
    printf("\t|\t%3d\t|\t%10d\t|\t%2d\t|\t%10d\t|\t%2d\t|\t%10d\t|\t%10d\t*\n",estacoes_Reserva[indice_ER].BusyBit, estacoes_Reserva[indice_ER].Op, estacoes_Reserva[indice_ER].Qj, estacoes_Reserva[indice_ER].Vj, estacoes_Reserva[indice_ER].Qk, estacoes_Reserva[indice_ER].Vk, estacoes_Reserva[indice_ER].A);
  }
  printf("*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*\n");
}
