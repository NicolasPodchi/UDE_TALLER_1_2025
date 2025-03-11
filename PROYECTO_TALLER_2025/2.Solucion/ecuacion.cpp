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
    nuevaEcuacion.discriminante = PRIMER_GRADO;

    strCrear(nuevaEcuacion.id);
    strCop(nuevaEcuacion.id, id);

    nuevaEcuacion.datos.primerGrado = crearEcuacionPrimerGrado(primerCoeficiente, segundoCoeficiente);

    return nuevaEcuacion;
}

ecuacion crearEcuacionSegundoGrado(strDinamico id, int primerCoeficiente, int segundCoeficiente, int tercerCoeficiente)
{
    ecuacion nuevaEcuacion;
    nuevaEcuacion.discriminante = SEGUNDO_GRADO;

    strCrear(nuevaEcuacion.id);
    strCop(nuevaEcuacion.id, id);

    nuevaEcuacion.datos.segundoGrado = crearEcuacionSegundoGrado(primerCoeficiente, segundCoeficiente, tercerCoeficiente);

    return nuevaEcuacion;
}

void mostrarEcuacion(ecuacion e)
{
    print(e.id);
    printf(": ");

    if (e.discriminante == PRIMER_GRADO)
        mostrarEcuacionPrimerGrado(e.datos.primerGrado);
    else
        mostrarEcuacionSegundoGrado(e.datos.segundoGrado);
}



void sumarDistintosGrados(ecuacion esg, ecuacion epg, ecuacion &nuevaEcuacion)
{
    nuevaEcuacion.discriminante = SEGUNDO_GRADO;
    nuevaEcuacion.datos.segundoGrado.primerCoeficiente = esg.datos.segundoGrado.primerCoeficiente;
    nuevaEcuacion.datos.segundoGrado.segundoCoeficiente = esg.datos.segundoGrado.segundoCoeficiente + epg.datos.primerGrado.primerCoeficiente;
    nuevaEcuacion.datos.segundoGrado.tercerCoeficiente = esg.datos.segundoGrado.tercerCoeficiente + epg.datos.primerGrado.segundoCoeficiente;
}

void sumarMismoGrado(ecuacion e1, ecuacion e2, ecuacion &nuevaEcuacion)
{
    if (e1.discriminante == SEGUNDO_GRADO)
    {
        if (e1.datos.segundoGrado.primerCoeficiente + e2.datos.segundoGrado.primerCoeficiente != 0)
        {
            nuevaEcuacion.discriminante = SEGUNDO_GRADO;
            nuevaEcuacion.datos.segundoGrado.primerCoeficiente = e1.datos.segundoGrado.primerCoeficiente + e2.datos.segundoGrado.primerCoeficiente;
            nuevaEcuacion.datos.segundoGrado.segundoCoeficiente = e1.datos.segundoGrado.segundoCoeficiente + e2.datos.segundoGrado.segundoCoeficiente;
            nuevaEcuacion.datos.segundoGrado.tercerCoeficiente = e1.datos.segundoGrado.tercerCoeficiente + e2.datos.segundoGrado.tercerCoeficiente;
        }
        else
        {
            nuevaEcuacion.discriminante = PRIMER_GRADO;
            nuevaEcuacion.datos.primerGrado.primerCoeficiente = e1.datos.segundoGrado.segundoCoeficiente + e2.datos.segundoGrado.segundoCoeficiente;
            nuevaEcuacion.datos.primerGrado.segundoCoeficiente = e1.datos.segundoGrado.tercerCoeficiente + e2.datos.segundoGrado.tercerCoeficiente;
        }
    }
    else
    {
        nuevaEcuacion.discriminante = PRIMER_GRADO;
        nuevaEcuacion.datos.primerGrado.primerCoeficiente = e1.datos.primerGrado.primerCoeficiente + e2.datos.primerGrado.primerCoeficiente;
        nuevaEcuacion.datos.primerGrado.segundoCoeficiente = e1.datos.primerGrado.segundoCoeficiente + e2.datos.primerGrado.segundoCoeficiente;
    }
}

ecuacion sumarEcuaciones(ecuacion e1, ecuacion e2, strDinamico id)
{
    ecuacion nuevaEcuacion;
    strCrear(nuevaEcuacion.id);
    strCop(nuevaEcuacion.id, id);

    if (e1.discriminante != e2.discriminante)
    {
        if (e1.discriminante == SEGUNDO_GRADO)
        {
            sumarDistintosGrados(e1, e2, nuevaEcuacion);
        }
        else
        {
            sumarDistintosGrados(e2, e1, nuevaEcuacion);
        }
    }
    else
    {
        sumarMismoGrado(e1, e2, nuevaEcuacion);
    }

    return nuevaEcuacion;
}

void destruirEcuacion(ecuacion &e)
{
    strDestruir(e.id);
}

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
void levantarEcuacion(strDinamico id, ecuacion &e)
{
    strDinamico nombreArchivo;
    convertirNombreArchivo(nombreArchivo, id);

    FILE * a;
    a = fopen(nombreArchivo, "rb");

    strCrear(e.id);
    levantarString(e.id,a);

    fread(&e.discriminante,sizeof(tipoEcuacion),1,a);

    if (e.discriminante == PRIMER_GRADO)
    {
        fread(&e.datos.primerGrado,sizeof(ecuacionPrimerGrado),1,a);
    }
    else
    {
        fread(&e.datos.segundoGrado,sizeof(ecuacionSegundoGrado),1,a);
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
