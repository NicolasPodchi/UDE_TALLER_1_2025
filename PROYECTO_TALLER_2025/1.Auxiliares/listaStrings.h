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

boolean vacia (listaStr l);

void parsing (strings s, listaStr &l);



#endif // LISTASTRINGS_H_INCLUDED
