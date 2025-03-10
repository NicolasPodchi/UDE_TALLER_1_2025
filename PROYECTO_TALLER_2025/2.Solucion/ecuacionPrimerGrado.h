#ifndef ECUACIONPRIMERGRADO_H_INCLUDED
#define ECUACIONPRIMERGRADO_H_INCLUDED
#include <stdio.h>
#include <math.h>

typedef struct {
    int primerCoeficiente;
    int segundoCoeficiente;
} ecuacionPrimerGrado;

int getPrimerCoeficiente (ecuacionPrimerGrado e);

int getSegundoCoeficiente (ecuacionPrimerGrado e);

ecuacionPrimerGrado crearEcuacionPrimerGrado (int primerCoeficiente, int segundoCoeficiente);

void mostrarPrimerCoeficiente (ecuacionPrimerGrado e);

void mostrarSegundoCoeficiente (ecuacionPrimerGrado e);

void mostrarEcuacionPrimerGrado(ecuacionPrimerGrado e);

float resolverPrimerGrado(ecuacionPrimerGrado e);

#endif // ECUACIONPRIMERGRADO_H_INCLUDED
