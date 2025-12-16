#ifndef MAZO_H
#define MAZO_H

#include "common.h"

typedef struct {
    tCarta cartas[40]; 
    int tope;         // El indice que dice cual es la siguiente carta (0 a 40)
} tMazo;

void extraerMazo(tMazo *pMazo);
void verMazo(tMazo *pMazo);

#endif