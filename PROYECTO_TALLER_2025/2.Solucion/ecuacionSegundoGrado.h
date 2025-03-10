#ifndef ECUACIONSEGUNDOGRADO_H_INCLUDED
#define ECUACIONSEGUNDOGRADO_H_INCLUDED
#include <stdio.h>
#include <math.h>

typedef struct {
    int primerCoeficiente;
    int segundoCoeficiente;
    int tercerCoeficiente;
} ecuacionSegundoGrado;


int getPrimerCoeficiente (ecuacionSegundoGrado e);

int getSegundoCoeficiente (ecuacionSegundoGrado e);

int getTercerCoeficiente (ecuacionSegundoGrado e);

ecuacionSegundoGrado crearEcuacionSegundoGrado (int primerCoeficiente, int segundoCoeficiente, int tercerCoeficiente);

void mostrarPrimerCoeficiente (ecuacionSegundoGrado e);

void mostrarSegundoCoeficiente (ecuacionSegundoGrado e);

void mostrarTercerCoeficiente (ecuacionSegundoGrado e);

void mostrarEcuacionSegundoGrado (ecuacionSegundoGrado NuevaEcuacion);

float resolverDiscriminante (ecuacionSegundoGrado e);

void resolverEcuacionDeDosResultados(ecuacionSegundoGrado e, float discriminante, float &resultado1, float &resultado2);

float resolverEcuacionDeUnSoloResultado (ecuacionSegundoGrado e);

#endif // ECUACIONSEGUNDOGRADO_H_INCLUDED
