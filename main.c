#include <stdio.h>
#include "include/common.h"
#include "include/mazo.h"

int main(){

    tMazo mazo;
    //inicializarMazo(mazo);
    extraerMazo(&mazo);
    verMazo(&mazo);

    return 0;
}