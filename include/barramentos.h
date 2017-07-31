#ifndef BARRAMENTOS_H
#define BARRAMENTOS_H

#include "definitions.h"

Barramento CDB; /*Common Data Bus*/
Barramento CMB; /*Cache <-> Memory Bus*/
Barramento PCB; /*Processor <-> Cache Bus*/

void inicializar_barramentos();
void inserir_no_barramento(Barramento b, int dado, int endereco, int controle);
void alterar_topo_barramento(Barramento b, int dado, int endereco, int controle);
void inserir_Dado_no_barramento(Barramento b, Dado_Barramento * d);
Dado_Barramento * get_topo_barramento(Barramento b);
Dado_Barramento * topo_barramento(Barramento b);
void inserir_no_barramento128bits(Barramento128bits *b, Dado_Barramento_128 * d, int endereco, int controle);

#endif
