#ifndef ECUACIONPRIMERGRADO_H_INCLUDED
#define ECUACIONPRIMERGRADO_H_INCLUDED
#include <math.h>

typedef struct {
    int primerCoeficiente;
    int segundoCoeficiente;
} ecuacionPrimerGrado;

ecuacionPrimerGrado crearEcuacionPrimerGrado (int primerCoeficiente, int segundoCoeficiente);

int getPrimerCoeficiente (ecuacionPrimerGrado e);

int getSegundoCoeficiente (ecuacionPrimerGrado e);

void mostrarPrimerCoeficiente (ecuacionPrimerGrado e);

void mostrarSegundoCoeficiente (ecuacionPrimerGrado e);

void mostrarEcuacionPrimerGrado(ecuacionPrimerGrado e);

void bajarEcuacionPrimerGrado (ecuacionPrimerGrado e, FILE * f);

float resolverPrimerGrado(ecuacionPrimerGrado e);

#endif // ECUACIONPRIMERGRADO_H_INCLUDED
