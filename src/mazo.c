#include <stdio.h>
#include <stdlib.h>
#include "../include/common.h"




typedef carta tMazo[40];

void extraerMazo(tMazo *pMazo);

int main() {
    tMazo mazo;
    extraerMazo(&mazo);
    
    return 0;
}


//ESTA FUNCION EXTRAE EL MAZO DE CARTAS DEL ARCHIVO BINARIO 
void extraerMazo(tMazo *pMazo) {
    FILE *archivo;
    carta pCarta;
    int i = 0;
    archivo = fopen("../dat/mazo.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }
    fread(&pCarta,sizeof(carta),1,archivo);
    while (!feof(archivo)){
        (*pMazo)[i] = pCarta;
        i++;
        fread(&pCarta,sizeof(carta),1,archivo);
    }
    

    fclose(archivo);
}