#ifndef COMMON_H
#define COMMON_H

typedef enum {
    ESPADAS,
    BASTOS,
    OROS,
    COPAS
} Palo;

typedef struct {
    int num;
    Palo palo;
    int jerarquia;
    int puntos; 
} tCarta;

#endif // CEMMON_C