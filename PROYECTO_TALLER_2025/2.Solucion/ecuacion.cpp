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

void crearEcuacion(listaStrDinamico l, ecuacion &e)
{
    int primerCoeficiente, segundoCoeficiente;
    if(cantidadParametros(l)==4)
    {
        e.discriminante = PRIMER_GRADO;
        l=l->sig;
        strCop(e.id,l->info);
        l=l->sig;
        e.
    }
}

//PRECONDICIÓN: El archivo viene abierto para escritura
void bajarEcuacion (ecuacion e, FILE * f)
{
    bajarString(e.id, f);

    if(e.discriminante == PRIMER_GRADO)
    {
        bajarEcuacionPrimerGrado();
    }
    else
    {
        bajarEcuacionSegundoGrado();
    }
}

//PRECONDICIÓN: El archivo viene abierto para lectura
void levantar_cliente (cliente &c, FILE * f)
{
    fread(&c.ci,sizeof(long int),1,f);
    strcrear(c.nombre);
    levantar_string(c.nombre,f);
    strcrear(c.apellido);
    levantar_string(c.apellido,f);
    strcrear(c.direccion);
    levantar_string(c.direccion,f);
    fread(&c.telefono,sizeof(long int),1,f);
    fread(&c.cant_reclamos,sizeof(int),1,f);
}
