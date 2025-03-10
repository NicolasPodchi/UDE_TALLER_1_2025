#include "ecuacionPrimerGrado.h"


int getPrimerCoeficiente(ecuacionPrimerGrado e)
{
    return e.primerCoeficiente;
}

int getSegundoCoeficiente(ecuacionPrimerGrado e)
{
    return e.segundoCoeficiente;
}

ecuacionPrimerGrado crearEcuacionPrimerGrado(int primerCoeficiente, int segundoCoeficiente)
{
    ecuacionPrimerGrado nuevaEcuacion;
    nuevaEcuacion.primerCoeficiente = primerCoeficiente;
    nuevaEcuacion.segundoCoeficiente = segundoCoeficiente;

    return nuevaEcuacion;
}

// Precondici�n: primerCoeficiente de e debe ser distinto de 0
void mostrarPrimerCoeficiente(ecuacionPrimerGrado e)
{
    if (e.primerCoeficiente != 1)
    {
        printf("%d", e.primerCoeficiente);
    }

    printf("x ");
}

void mostrarSegundoCoeficiente(ecuacionPrimerGrado e)
{
    if (e.segundoCoeficiente != 0)
    {
        int segundoCoeficienteMostrar = e.segundoCoeficiente;

        if (e.segundoCoeficiente < 0)
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

float resolverPrimerGrado(ecuacionPrimerGrado e)
{
    return e.segundoCoeficiente * -1 / e.primerCoeficiente; // fijarse si es mejor usar el getcoeficiente o llamarlo asi!!!!!
}
