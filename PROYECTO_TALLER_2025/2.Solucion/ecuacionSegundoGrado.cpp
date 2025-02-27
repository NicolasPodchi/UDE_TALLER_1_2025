#include <stdio.h>
#include "ecuacionSegundoGrado.h"

ecuacionSegundoGrado crearEcuacionSegundoGrado (int primerCoeficiente, int segundoCoeficiente, int tercerCoeficiente)
{
    ecuacionSegundoGrado nuevaEcuacion;
    nuevaEcuacion.primerCoeficiente = primerCoeficiente;
    nuevaEcuacion.segundoCoeficiente = segundoCoeficiente;
    nuevaEcuacion.tercerCoeficiente = tercerCoeficiente;

    return nuevaEcuacion;
}

int getPrimerCoeficiente (ecuacionSegundoGrado e)
{
    return e.primerCoeficiente;
}

int getSegundoCoeficiente (ecuacionSegundoGrado e)
{
    return e.segundoCoeficiente;
}

int getTercerCoeficiente (ecuacionSegundoGrado e)
{
    return e.tercerCoeficiente;
}

void mostrarPrimerCoeficiente (ecuacionSegundoGrado e)
{
    printf("%d", e.primerCoeficiente);
}

void mostrarSegundoCoeficiente (ecuacionSegundoGrado e)
{
    printf("%d", e.segundoCoeficiente);
}

void mostrarTercerCoeficiente (ecuacionSegundoGrado e)
{
    printf("%d", e.tercerCoeficiente);
}
