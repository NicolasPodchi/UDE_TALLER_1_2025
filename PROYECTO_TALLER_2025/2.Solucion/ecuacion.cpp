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

//void resolverEcuacion(ecuacion e, boolean &DosResultados, float &Resu1, float &Resu2)
//{
//
//    ecuacionPrimerGrado EcuacionAuxiliar;
//    if (getTipo(e) == PRIMER_GRADO)
//    {
//        EcuacionAuxiliar = getEcuacionPrimerGrado(e);  //-b/a
//        Resu1 = ResolverPrimerGrado(EcuacionAuxiliar); // fijarse si es mejor usar el getcoeficiente o llamarlo asi!!!!!
//    }
//    else
//    {
//        ecuacionSegundoGrado Ecu2Auxiliar = getEcuacionSegundoGrado(e);
//        ResolverSegundoGrado(Ecu2Auxiliar, DosResultados, Resu1, Resu2);
//    }
//}

// PRECONDICI�N: El archivo viene abierto para escritura
void bajarEcuacion(ecuacion e, FILE *f)
{
    bajarString(e.id, f);
    fwrite(&e.discriminante, sizeof(tipoEcuacion), 1, f);

    if (e.discriminante == PRIMER_GRADO)
    {
        fwrite(&e.datos.primerGrado, sizeof(ecuacionPrimerGrado), 1, f);
    }
    else
    {
        fwrite(&e.datos.segundoGrado, sizeof(ecuacionSegundoGrado), 1, f);
    }
}

// PRECONDICI�N: El archivo viene abierto para lectura
// void levantar_cliente (cliente &c, FILE * f)
//{
//     fread(&c.ci,sizeof(long int),1,f);
//     strcrear(c.nombre);
//     levantar_string(c.nombre,f);
//     strcrear(c.apellido);
//     levantar_string(c.apellido,f);
//     strcrear(c.direccion);
//     levantar_string(c.direccion,f);
//     fread(&c.telefono,sizeof(long int),1,f);
//     fread(&c.cant_reclamos,sizeof(int),1,f);
// }
