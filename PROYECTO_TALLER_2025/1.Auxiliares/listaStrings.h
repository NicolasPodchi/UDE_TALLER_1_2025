#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED

#include "strDinamico.h"

typedef struct nodoL
{
    strings s;
    nodoL * sig;
} nodoLista;

typedef nodoLista * listaStr;

void crearLista (listaStr &l);

listaStrDinamico parsing(strDinamico s);

int cantidadParametros(listaStrDinamico l);

//Precondici�n: p debe pertenecer a una posici�n con datos dentro de l
strDinamico obtenerParametroEnPosicion(listaStrDinamico l, int p);

#endif // LISTASTRINGS_H_INCLUDED
