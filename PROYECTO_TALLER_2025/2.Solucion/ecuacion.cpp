#include "ecuacion.h"

void getId(ecuacion e, strDinamico &s)
{
    strCop(s, e.id);
}

tipoEcuacion getTipo(ecuacion e)
{
    return e.discriminante;
}

ecuacionPrimerGrado getEcuacionPrimerGrado(ecuacion e)
{
    return e.datos.primerGrado;
}

ecuacionSegundoGrado getEcuacionSegundoGrado(ecuacion e)
{
    return e.datos.segundoGrado;
}

ecuacion crearEcuacionPrimerGrado(strDinamico id, int primerCoeficiente, int segundoCoeficiente)
{
    ecuacion nuevaEcuacion;
    strCrear(nuevaEcuacion.id);

    nuevaEcuacion.discriminante = PRIMER_GRADO;
    strCop(nuevaEcuacion.id, id);
    nuevaEcuacion.datos.primerGrado = crearEcuacionPrimerGrado(primerCoeficiente, segundoCoeficiente);
}

ecuacion crearEcuacionSegundoGrado(strDinamico id, int primerCoeficiente, int segundCoeficiente, int tercerCoeficiente)
{
    ecuacion nuevaEcuacion;

    nuevaEcuacion.discriminante = SEGUNDO_GRADO;
    strCop(nuevaEcuacion.id, id);
    nuevaEcuacion.datos.segundoGrado = crearEcuacionSegundoGrado(primerCoeficiente, segundCoeficiente, tercerCoeficiente);
}

void mostrarEcuacion(ecuacion e)
{
    if (e.discriminante == PRIMER_GRADO)
        mostrarEcuacionPrimerGrado(e.datos.primerGrado);
    else
        mostrarEcuacionSegundoGrado(e.datos.segundoGrado);
}

// void resolverEcuacion(ecuacion e, boolean &DosResultados, float &Resu1, float &Resu2)
//{
//
//     ecuacionPrimerGrado EcuacionAuxiliar;
//     if (getTipo(e) == PRIMER_GRADO)
//     {
//         EcuacionAuxiliar = getEcuacionPrimerGrado(e);  //-b/a
//         Resu1 = ResolverPrimerGrado(EcuacionAuxiliar); // fijarse si es mejor usar el getcoeficiente o llamarlo asi!!!!!
//     }
//     else
//     {
//         ecuacionSegundoGrado Ecu2Auxiliar = getEcuacionSegundoGrado(e);
//         ResolverSegundoGrado(Ecu2Auxiliar, DosResultados, Resu1, Resu2);
//     }
// }

// PRECONDICI�N: El archivo viene abierto para escritura
void bajarEcuacion(ecuacion e)
{
    strDinamico nombreArchivo;
    convertirNombreArchivo(nombreArchivo, e.id);

    FILE * a;
    a = fopen(nombreArchivo, "wb");

    bajarString(e.id, a);
    fwrite(&e.discriminante, sizeof(tipoEcuacion), 1, a);

    if (e.discriminante == PRIMER_GRADO)
    {
        fwrite(&e.datos.primerGrado, sizeof(ecuacionPrimerGrado), 1, a);
    }
    else
    {
        fwrite(&e.datos.segundoGrado, sizeof(ecuacionSegundoGrado), 1, a);
    }

    fclose(a);
}

// PRECONDICI�N: El archivo viene abierto para lectura
void levantarEcuacion(ecuacion &e, FILE * f)
{
    strCrear(e.id);
    levantarString(e.id,f);

    fread(&e.discriminante,sizeof(tipoEcuacion),1,f);

    if (e.discriminante == PRIMER_GRADO)
    {
        fread(&e.datos.primerGrado,sizeof(ecuacionPrimerGrado),1,f);
    }
    else
    {
        fread(&e.datos.segundoGrado,sizeof(ecuacionSegundoGrado),1,f);
    }
}

boolean existeIdEcuacionArchivo(strDinamico id)
{
    boolean existe=FALSE;
    FILE * a;

    strDinamico nombreArchivo;
    convertirNombreArchivo(nombreArchivo, id);

    a = fopen(nombreArchivo, "rb");

    if(a!=NULL)
        existe= TRUE;

    fclose(a);

    return existe;
}

ecuacion sumarEcuaciones(ecuacion e1, ecuacion e2, strDinamico id)
{
    ecuacion nuevaEcuacion;
    strCrear(nuevaEcuacion.id);
    strCop(nuevaEcuacion.id, id);

    nuevaEcuacion.discriminante = PRIMER_GRADO;

    if(e1.discriminante != e2.discriminante)
    {
        nuevaEcuacion.discriminante = SEGUNDO_GRADO;

        if(e2.discriminante == SEGUNDO_GRADO)
        {
            ecuacion aux = e1;
            e1 = e2;
            e2 = aux;
        }

        //se suman dos ecucaciones distintas y tiene como resultado una de segundo grado
        nuevaEcuacion.datos.segundoGrado.primerCoeficiente = e1.datos.segundoGrado.primerCoeficiente;
        nuevaEcuacion.datos.segundoGrado.segundoCoeficiente = e1.datos.segundoGrado.segundoCoeficiente + e2.datos.primerGrado.primerCoeficiente;
        nuevaEcuacion.datos.segundoGrado.tercerCoeficiente = e1.datos.segundoGrado.tercerCoeficiente + e2.datos.primerGrado.segundoCoeficiente;
    }
    else
    {
        if(e1.discriminante == SEGUNDO_GRADO)
        {
            if(abs(e1.datos.segundoGrado.primerCoeficiente) - abs(e2.datos.segundoGrado.primerCoeficiente) != 0)
            {
                // se suman dos ecuaciones de segundo grado pero no se anula el primer coeficiente
                nuevaEcuacion.datos.segundoGrado.primerCoeficiente = e1.datos.segundoGrado.primerCoeficiente + e2.datos.segundoGrado.primerCoeficiente;
                nuevaEcuacion.datos.segundoGrado.segundoCoeficiente = e1.datos.segundoGrado.segundoCoeficiente + e2.datos.segundoGrado.segundoCoeficiente;
                nuevaEcuacion.datos.segundoGrado.tercerCoeficiente = e1.datos.segundoGrado.tercerCoeficiente + e2.datos.segundoGrado.tercerCoeficiente;

                nuevaEcuacion.discriminante = SEGUNDO_GRADO;
            }
            else
            {
                // se anula primer coeficiente en suma de dos ecuaciones de segundo grado
                nuevaEcuacion.datos.primerGrado.primerCoeficiente = e1.datos.segundoGrado.segundoCoeficiente + e2.datos.segundoGrado.segundoCoeficiente;
                nuevaEcuacion.datos.primerGrado.segundoCoeficiente = e1.datos.segundoGrado.tercerCoeficiente + e2.datos.segundoGrado.tercerCoeficiente;
            }
        }
        else
        {
            // son las dos de primer grado
            nuevaEcuacion.datos.primerGrado.primerCoeficiente = e1.datos.primerGrado.primerCoeficiente + e2.datos.primerGrado.primerCoeficiente;
            nuevaEcuacion.datos.primerGrado.segundoCoeficiente = e1.datos.primerGrado.segundoCoeficiente + e2.datos.primerGrado.segundoCoeficiente;
        }
    }

    return nuevaEcuacion;
}
