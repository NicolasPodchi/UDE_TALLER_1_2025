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

void ResolverSegundoGrado(ecuacionSegundoGrado e, float &Resu1, float &Resu2);

void ResolucionDiscriminanteMayora0(ecuacionSegundoGrado e, float discriminante, int &Resultado1, int &Resultado2);
#endif // ECUACIONSEGUNDOGRADO_H_INCLUDED
