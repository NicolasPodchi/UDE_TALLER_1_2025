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

void crear (arbolEcuacion &a);
//PRECONDICION: El arbol debe haberse inicializado anteriormente
//Saber si un arbol esta vacio
boolean arbolVacio(arbolEcuacion a);

//PRECONDICION: el arbol no es nulo
//Obtener la raiz del arbol
ecuacion darRaiz (arbolEcuacion a);

//PRECONDICION: el arbol no es nulo
//Devolver un subarbol izquierdo
arbolEcuacion hijoIzquierdo (arbolEcuacion a);

//PRECONDICION: el arbol no es nulo
//Devolver un subarbol derecho
arbolEcuacion hijoDerecho (arbolEcuacion a);

//PRECONDICION: El arbol debe haberse inicializado anteriormente
//Precondicion: El id de la nueva ecuacion no debe existir dentro del ABB
void insertarEcuacion (arbolEcuacion &a, ecuacion e);

//Precondicion: El ABB de ecuaciones no debe estar vacio
boolean existeIdEcuacion(arbolEcuacion a, strDinamico id);

//Precondicion: El ABB no puede estar vacio e id debe existir en el ABB
ecuacion obtenerEcuacionPorId(arbolEcuacion a, strDinamico id);

//Precondicion: El ABB de ecuaciones no debe estar vacio
void mostrarArbol(arbolEcuacion a);

void destruirArbol(arbolEcuacion &a);

#endif // ARBOLECUACION_H_INCLUDED
