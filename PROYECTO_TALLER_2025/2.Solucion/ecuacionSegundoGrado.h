#ifndef ECUACIONSEGUNDOGRADO_H_INCLUDED
#define ECUACIONSEGUNDOGRADO_H_INCLUDED

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

#endif // ECUACIONSEGUNDOGRADO_H_INCLUDED
