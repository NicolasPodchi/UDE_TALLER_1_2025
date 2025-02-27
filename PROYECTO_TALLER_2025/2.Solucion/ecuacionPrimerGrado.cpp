#include <stdio.h>
#include "ecuacionPrimerGrado.h"

ecuacionPrimerGrado crearEcuacionPrimerGrado (int primerCoeficiente, int segundoCoeficiente)
{
    ecuacionPrimerGrado nuevaEcuacion;
    nuevaEcuacion.primerCoeficiente = primerCoeficiente;
    nuevaEcuacion.segundoCoeficiente = segundoCoeficiente;

    return nuevaEcuacion;
}

int getPrimerCoeficiente (ecuacionPrimerGrado e)
{
    return e.primerCoeficiente;
}

int getSegundoCoeficiente (ecuacionPrimerGrado e)
{
    return e.segundoCoeficiente;
}

//Precondición: primerCoeficiente de e debe ser distinto de 0
void mostrarPrimerCoeficiente (ecuacionPrimerGrado e)
{
    if(e.primerCoeficiente != 1)
    {
        printf("%d", e.primerCoeficiente);
    }

    printf("x ");
}

void mostrarSegundoCoeficiente (ecuacionPrimerGrado e)
{
    if(e.segundoCoeficiente != 0)
    {
        int segundoCoeficienteMostrar = e.segundoCoeficiente;

        if(e.segundoCoeficiente < 0)
        {
            printf("- ");
            segundoCoeficienteMostrar = segundoCoeficienteMostrar * -1;
        }
        else
        {
            printf("+ ");
        }

        printf("%d ", segundoCoeficienteMostrar);
    }
}

void mostrarEcuacionPrimerGrado(ecuacionPrimerGrado e)
{
    mostrarPrimerCoeficiente(e);
    mostrarSegundoCoeficiente(e);

    printf("= 0");
}

