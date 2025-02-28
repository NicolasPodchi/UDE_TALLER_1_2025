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

        printf("%d", SegundoCoeficienteMostrar);
        printf("x ");
    }
}

void mostrarTercerCoeficiente(ecuacionSegundoGrado e)
{
    if (e.tercerCoeficiente != 0)
    {
        int tercercoeficienteMOtrar = e.tercerCoeficiente;

        if (e.tercerCoeficiente < 0)
        {
            printf("- ");
            tercercoeficienteMOtrar = tercercoeficienteMOtrar * -1;
        }
        else
        {
            printf("+ ");
        }

        printf("%d ", tercercoeficienteMOtrar);
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

//void ResolverSegundoGrado(ecuacionSegundoGrado e, boolean &DosResu, float &Resu1, float &Resu2) // no se contempla discriminante < 0 se debe controlar antes
//{
//    float discriminante = e.segundoCoeficiente * e.segundoCoeficiente;
//    discriminante = discriminante - (4 * e.primerCoeficiente * e.tercerCoeficiente);
//    if (discriminante > 0)
//    {
//        float PrimerTermino = e.segundoCoeficiente * -1;
//        float SegundoTermino = sqrt(discriminante);
//        DosResu = TRUE;
//        Resu1 = PrimerTermino + SegundoTermino;
//        Resu2 = PrimerTermino - SegundoTermino;
//    }
//    else
//        Resu1 = e.segundoCoeficiente * -1 / e.primerCoeficiente * 2;
//}
