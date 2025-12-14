#include <stdio.h>
#include <stdlib.h>
#include "../include/common.h"

typedef carta tMazo[40];


int extraerMazo(tMazo pMazo);
void verMazo(tMazo pMazo, int n);

int main() {
    tMazo mazo;
    //inicializarMazo(mazo);
    int n = extraerMazo(mazo);
    verMazo(mazo, n);
    
    return 0;
}


//ESTA FUNCION EXTRAE EL MAZO DE CARTAS DEL ARCHIVO BINARIO 
int extraerMazo(tMazo pMazo) {
    FILE *archivo;
    carta pCarta;
    int i = 0;
    archivo = fopen("../../dat/mazo.dat", "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 0;
    }
    while (i < 40 && fread(&pCarta, sizeof(carta), 1, archivo) == 1) {
        pMazo[i++] = pCarta;
    }

    fclose(archivo);
    return i;
}

//haceme una funcion para ver el mazo de cartas por pantalla
void verMazo(tMazo pMazo, int n) {
    for (int i = 0; i < n; i++) {
        printf("Carta %d: Num: %d, Palo: %d, Jerarquia: %d, Puntos: %d\n\n", i+1, pMazo[i].num, pMazo[i].palo, pMazo[i].jerarquia, pMazo[i].puntos);
    }
}
