#include <stdio.h>
#include <stdlib.h>
#include "../include/common.h"
#include "../include/mazo.h"
#include <time.h>


//ESTA FUNCION EXTRAE EL MAZO DE CARTAS DEL ARCHIVO BINARIO 
void extraerMazo(tMazo *pMazo) {
    FILE *archivo;
    archivo = fopen("../../dat/mazo.dat", "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
    }
    
    fread(pMazo->cartas, sizeof(tCarta), 40, archivo);

    fclose(archivo);
}

//haceme una funcion para ver el mazo de cartas por pantalla
void verMazo(tMazo *pMazo) {
    for (int i = 0; i < 40; i++) {
        printf("Carta %d: Numero: %d, Palo: %d, Jerarquia: %d, Puntos: %d\n", 
               i + 1, 
               pMazo->cartas[i].num, 
               pMazo->cartas[i].palo, 
               pMazo->cartas[i].jerarquia, 
               pMazo->cartas[i].puntos);
    }
}

void mezclarMazo(tMazo *pMazo) {
    srand(time(NULL));
    for (int i = 0; i < 40; i++){
        int j = rand() % 40;
        tCarta temp = pMazo->cartas[i];
        pMazo->cartas[i] = pMazo->cartas[j];
        pMazo->cartas[j] = temp;
    }
}

int repartirMazo(tMazo *pMazo, tCarta *destino){
    if(pMazo->tope + 3 > 40){
        return 0; // No hay suficientes cartas
    }
    
    destino[0] = pMazo->cartas[pMazo->tope];
    destino[1] = pMazo->cartas[pMazo->tope + 1];
    destino[2] = pMazo->cartas[pMazo->tope + 2];

    pMazo->tope += 3;
     
    return 1;
}

int main() {
    tMazo mazo;
    //inicializarMazo(mazo);
    extraerMazo(&mazo);
    verMazo(&mazo);
    
    return 0;
}
