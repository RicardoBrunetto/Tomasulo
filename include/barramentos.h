#ifndef BARRAMENTOS_H
#define BARRAMENTOS_H

#include "definitions.h"

Barramento CDB; /*Common Data Bus*/
Barramento CMB; /*Cache <-> Memory Bus*/
Barramento PCB; /*Processor <-> Cache Bus*/
Barramento PCLB; /*Processor <-> Clock Bus*/

void inicializar_barramentos();

#endif
