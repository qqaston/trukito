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
} carta;

#endif // CEMMON_C