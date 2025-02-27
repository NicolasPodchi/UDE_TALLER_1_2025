#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED

#include "strDinamico.h"

typedef struct nodoL
{
    strDinamico info;
    nodoL * sig;
} nodoLista;

typedef nodoLista * listaStrDinamico;

void crearListaStrings (listaStrDinamico &l);

void insBack (listaStrDinamico &l, strDinamico s);

listaStrDinamico parsing(strDinamico s);

int cantidadParametros(listaStrDinamico l);

//Precondición: p debe pertenecer a una posición con datos dentro de l
void obtenerParametroEnPosicion(listaStrDinamico l, int p, strDinamico & s);

listaStrDinamico parsing(strDinamico s);

void mostrarLista (listaStrDinamico l);

#endif // LISTASTRINGS_H_INCLUDED
