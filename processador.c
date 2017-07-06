#include "processador.h"

#include <string.h>

/*Função que simula a estágio de Busca do Pipeline*/
void PIPELINE_fetch(){
  IR.valor = mem_read(PC.valor); /*Insere a instrução não-decodificada no */
  PC.valor = PC.valor + 4; /*Incrementa PC*/
}

/*Função que simula a estágio de Decodificação do Pipeline
  Pega a instrução [conjunto de Bytes] do IR
  Decodifica a instrução e a insere na fila*/
void PIPELINE_decode(){
  Instrucao * i = decodificar(IR.valor); /*Decodifica a instrução, retornando um ponteiro para Instruction*/
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

/*Função que simula a estágio de Decodificação do Pipeline
  Recebe como parâmetro um conjunto de instruções [em bytes]
  Gera na saída as instruções decodificadas [tipo Instrucao]*/
void PIPELINE_write(Instrucao instr){
  //get_tipo_instrucao();
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

void processador_next(){

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
