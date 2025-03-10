#include <stdio.h>
#include "ecuacionSegundoGrado.h"

ecuacionSegundoGrado crearEcuacionSegundoGrado(int primerCoeficiente, int segundoCoeficiente, int tercerCoeficiente)
{
    ecuacionSegundoGrado nuevaEcuacion;
    nuevaEcuacion.primerCoeficiente = primerCoeficiente;
    nuevaEcuacion.segundoCoeficiente = segundoCoeficiente;
    nuevaEcuacion.tercerCoeficiente = tercerCoeficiente;

    return nuevaEcuacion;
}

int getPrimerCoeficiente(ecuacionSegundoGrado e)
{
    return e.primerCoeficiente;
}

int getSegundoCoeficiente(ecuacionSegundoGrado e)
{
    return e.segundoCoeficiente;
}

int getTercerCoeficiente(ecuacionSegundoGrado e)
{
    return e.tercerCoeficiente;
}

void mostrarPrimerCoeficiente(ecuacionSegundoGrado e)
{
    if (e.primerCoeficiente != 1)
    {
        printf("%d", e.primerCoeficiente);
    }

    printf("x^2 ");
}

void mostrarSegundoCoeficiente(ecuacionSegundoGrado e)
{
    if (e.segundoCoeficiente != 0)
    {
        int SegundoCoeficienteMostrar = e.segundoCoeficiente;

        if (e.segundoCoeficiente < 0)
        {
            printf("- ");
            SegundoCoeficienteMostrar = SegundoCoeficienteMostrar * -1;
        }
        else
        {
            printf("+ ");
        }

        if ( e.segundoCoeficiente != 1)
            printf("%d", SegundoCoeficienteMostrar);

        printf("x ");
    }
}

void mostrarTercerCoeficiente(ecuacionSegundoGrado e)
{
    if (e.tercerCoeficiente != 0)
    {
        int tercercoeficienteMostrar = e.tercerCoeficiente;

        if (e.tercerCoeficiente < 0)
        {
            printf("- ");
            tercercoeficienteMostrar = tercercoeficienteMostrar * -1;
        }
        else
        {
            printf("+ ");
        }

        printf("%d ", tercercoeficienteMostrar);
    }
}

void mostrarEcuacionSegundoGrado(ecuacionSegundoGrado NuevaEcuacion)
{
    mostrarPrimerCoeficiente(NuevaEcuacion);
    mostrarSegundoCoeficiente(NuevaEcuacion);
    mostrarTercerCoeficiente(NuevaEcuacion);
    printf("= 0");
}

void bajarEcuacionSegundoGrado(ecuacionSegundoGrado e, FILE *f)
{
    fwrite(&e.primerCoeficiente, sizeof(int), 1, f);
    fwrite(&e.segundoCoeficiente, sizeof(int), 1, f);
    fwrite(&e.tercerCoeficiente, sizeof(int), 1, f);
}

float resolverDiscriminante (ecuacionSegundoGrado e)
{
    float discriminante=e.segundoCoeficiente*e.segundoCoeficiente;
    discriminante = discriminante - (4 * e.primerCoeficiente * e.tercerCoeficiente);
    return discriminante;
}

void resolverEcuacionDeDosResultados(ecuacionSegundoGrado e, float discriminante, float &resultado1, float &resultado2)
{
    float primerTermino = e.segundoCoeficiente * -1;
    float segundoTermino = sqrt(discriminante);
    float divisor = 2 * e.primerCoeficiente;

    resultado1 = (primerTermino + segundoTermino) / divisor;
    resultado2 = (primerTermino - segundoTermino) / divisor;
}

float resolverEcuacionDeUnSoloResultado (ecuacionSegundoGrado e)
{
    return(-e.segundoCoeficiente) / (2 * e.primerCoeficiente);
}
