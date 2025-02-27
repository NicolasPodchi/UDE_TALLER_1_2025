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

void crearEcuacionPrimerGrado( ecuacion &e, strDinamico id, int primerCoeficiente, int segundoCoeficiente)
{
    e.discriminante = PRIMER_GRADO;
    strCop(e.id, id);
    e.datos.primerGrado = crearEcuacionPrimerGrado(primerCoeficiente, segundoCoeficiente);
}

void crearEcuacionSegundoGrado(ecuacion &e, strDinamico id, int primerCoeficiente, int segundCoeficiente, int tercerCoeficiente)
{
    e.discriminante = SEGUNDO_GRADO;
    strCop(e.id, id);
    e.datos.segundoGrado = crearEcuacionSegundoGrado(primerCoeficiente, segundCoeficiente, tercerCoeficiente);
}

void mostrarEcuacion(ecuacion e)
{
    if(e.discriminante ==PRIMER_GRADO)
        mostrarEcuacionPrimerGrado(e.datos.primerGrado);
    else
        mostrarEcuacionSegundoGrado(e.datos.segundoGrado);
}

////PRECONDICIÓN: El archivo viene abierto para escritura
//void bajarEcuacion (ecuacion e, FILE * f)
//{
//    bajarString(e.id, f);
//
//    if(e.discriminante == PRIMER_GRADO)
//    {
//        bajarEcuacionPrimerGrado(e.datos.primerGrado);
//    }
//    else
//    {
//        bajarEcuacionSegundoGrado();
//    }
//}

////PRECONDICIÓN: El archivo viene abierto para lectura
//void levantar_cliente (cliente &c, FILE * f)
//{
//    fread(&c.ci,sizeof(long int),1,f);
//    strcrear(c.nombre);
//    levantar_string(c.nombre,f);
//    strcrear(c.apellido);
//    levantar_string(c.apellido,f);
//    strcrear(c.direccion);
//    levantar_string(c.direccion,f);
//    fread(&c.telefono,sizeof(long int),1,f);
//    fread(&c.cant_reclamos,sizeof(int),1,f);
//}
