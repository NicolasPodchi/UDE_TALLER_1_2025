#ifndef ECUACIONSEGUNDOGRADO_H_INCLUDED
#define ECUACIONSEGUNDOGRADO_H_INCLUDED
#include "../1.Auxiliares/boolean.h"
#include <math.h>

typedef struct {
    int primerCoeficiente;
    int segundoCoeficiente;
    int tercerCoeficiente;
} ecuacionSegundoGrado;

ecuacionSegundoGrado crearEcuacionSegundoGrado (int primerCoeficiente, int segundoCoeficiente, int tercerCoeficiente);

int getPrimerCoeficiente (ecuacionSegundoGrado e);

int getSegundoCoeficiente (ecuacionSegundoGrado e);

int getTercerCoeficiente (ecuacionSegundoGrado e);

void mostrarPrimerCoeficiente (ecuacionSegundoGrado e);

void mostrarSegundoCoeficiente (ecuacionSegundoGrado e);

void mostrarTercerCoeficiente (ecuacionSegundoGrado e);

void mostrarEcuacionSegundoGrado (ecuacionSegundoGrado NuevaEcuacion);

void bajarEcuacionSegundoGrado (ecuacionSegundoGrado e, FILE * f);

float resolverDiscriminante (ecuacionSegundoGrado e);

void resolverEcuacionDeDosResultados(ecuacionSegundoGrado e, float discriminante, float &resultado1, float &resultado2);

float resolverEcuacionDeUnSoloResultado (ecuacionSegundoGrado e);

#endif // ECUACIONSEGUNDOGRADO_H_INCLUDED
