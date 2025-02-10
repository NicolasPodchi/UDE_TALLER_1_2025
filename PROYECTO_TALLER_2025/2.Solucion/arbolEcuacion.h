#ifndef ARBOLECUACION_H_INCLUDED
#define ARBOLECUACION_H_INCLUDED
#include "ecuacion.h"

typedef struct nodoA
{
    ecuacion info;
    nodoA * hIzq;
    nodoA * hDer;

} nodoArbol;

typedef nodoArbol * arbolEcuacion;



#endif // ARBOLECUACION_H_INCLUDED
