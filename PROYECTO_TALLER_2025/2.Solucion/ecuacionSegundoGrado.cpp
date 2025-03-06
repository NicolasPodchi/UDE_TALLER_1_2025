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

float ResolverDiscriminante (ecuacionSegundoGrado e)
{
    float discriminante=e.segundoCoeficiente*e.segundoCoeficiente;
     discriminante = discriminante - (4 * e.primerCoeficiente * e.tercerCoeficiente);
     return discriminante;

}

void ResolucionDiscriminanteMayora0(ecuacionSegundoGrado e, float discriminante, int &Resultado1, int &Resultado2) {
    float PrimerTermino = e.segundoCoeficiente * -1;
    float SegundoTermino = sqrt(discriminante);
    float divisor = 2 * e.primerCoeficiente;

    Resultado1 = (PrimerTermino + SegundoTermino) / divisor;
    Resultado2 = (PrimerTermino - SegundoTermino) / divisor;
}
void ResolverSegundoGrado(ecuacionSegundoGrado e, float &Resu1, float &Resu2)
{
    int Resultado1, Resultado2;
    float discriminante = ResolverDiscriminante(e);

    //  evitar division por cero
    if (e.primerCoeficiente == 0)
        printf("ERROR: No es una ecuación de segundo grado.\n");

    if (discriminante > 0)
    {
        ResolucionDiscriminanteMayora0(e, discriminante, Resultado1, Resultado2);
        Resu1 = Resultado1;
        Resu2 = Resultado2;
        printf("EXISTEN DOS SOLUCIONES \nRESULTADO 1: %d\nRESULTADO 2: %d\n", Resultado1, Resultado2);
    } else
    {
        Resu1 = (-e.segundoCoeficiente) / (2 * e.primerCoeficiente);
        Resu2 = 0;  //  evitar basura
        printf("EXISTE UNA ÚNICA SOLUCIÓN \nRESULTADO: %f\n", Resu1);
    }
}
