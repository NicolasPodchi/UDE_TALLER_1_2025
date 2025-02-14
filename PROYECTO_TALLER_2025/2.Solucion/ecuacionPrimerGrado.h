#ifndef ECUACIONPRIMERGRADO_H_INCLUDED
#define ECUACIONPRIMERGRADO_H_INCLUDED
#include <math.h>

typedef struct {
    int primerCoeficiente;
    int segundoCoeficiente;
} ecuacionPrimerGrado;

ecuacionPrimerGrado crearPrimerGrado (int primerCoeficiente, int segundoCoeficiente);


#endif // ECUACIONPRIMERGRADO_H_INCLUDED
