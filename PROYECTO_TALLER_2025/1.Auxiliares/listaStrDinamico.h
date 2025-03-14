#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED
#include <stdio.h>
#include "strDinamico.h"

typedef struct nodoL
{
    strDinamico info;
    nodoL * sig;
} nodoLista;

typedef nodoLista * listaStrDinamico;

void crearListaStrings (listaStrDinamico &l);

void destruirListaStrings (listaStrDinamico &l);

void insBack (listaStrDinamico &l, strDinamico s);

int cantidadParametros(listaStrDinamico l);

//Precondición: p debe pertenecer a una posición con datos dentro de l
void obtenerParametroEnPosicion(listaStrDinamico l, int p, strDinamico & s);

void parsing(strDinamico s, listaStrDinamico &l);

void mostrarLista (listaStrDinamico l);

#endif // LISTASTRINGS_H_INCLUDED
