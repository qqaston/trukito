#include <stdio.h>
#include <stdlib.h>
#include "../include/common.h"

FILE *archivoMazo;

void crearMazo(){
    archivoMazo = fopen("mazo.dat", "wb");
    if (archivoMazo == NULL) {
        perror("Error al crear el archivo del mazo");
        exit(EXIT_FAILURE);
    }

    carta nuevaCarta;
    int jerarquia;

    for (Palo palo = ESPADAS; palo <= COPAS; palo++) {
        for (int num = 1; num <= 12; num++) {
            if(num != 8 && num != 9){
                            if (palo == ESPADAS && num == 1) {
                            jerarquia = 14;
                        }else if (palo == BASTOS && num == 1) {
                            jerarquia = 13;
                        }else if (palo == ESPADAS && num == 7) {
                            jerarquia = 12;
                        }else if (palo == OROS && num == 7){
                            jerarquia = 11;                
                        }else if (num == 3) {
                            jerarquia = 10;
                        }else if (num == 2) {
                            jerarquia = 9;
                        }else if ((palo == OROS || palo == COPAS) && num == 1) {
                            jerarquia = 8;
                        }else{
                            jerarquia = num;
                        }

                        
                        nuevaCarta.num = num;
                        nuevaCarta.palo = palo;
                        nuevaCarta.jerarquia = jerarquia;
                        if(num == 12 || num == 11 || num == 10) {
                            nuevaCarta.puntos = 0;
                        }else{
                            nuevaCarta.puntos = num;
                        }
                        printf("Carta creada: Num %d, Palo %d, Jerarquia %d, Puntos %d\n", nuevaCarta.num, nuevaCarta.palo, nuevaCarta.jerarquia, nuevaCarta.puntos);
                        printf("==============================================================\n");
                        fwrite(&nuevaCarta, sizeof(carta), 1, archivoMazo);
            }
            
            
        }

        printf("\n\n\n");
    }
}


int main(){

    crearMazo();
    fclose(archivoMazo);
    system("pause");

    return 0;
}