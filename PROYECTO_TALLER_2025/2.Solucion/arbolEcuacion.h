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

void destruirArbol(arbolEcuacion &a);

//PRECONDICION: El arbol debe haberse inicializado anteriormente
//Saber si un �rbol est� vac�o
boolean arbolVacio(arbolEcuacion a);


//PRECONDICION: el �rbol no es nulo
//Obtener la ra�z del �rbol
ecuacion darRaiz (arbolEcuacion a);

//PRECONDICION: el �rbol no es nulo
//Devolver un sub�rbol izquierdo
arbolEcuacion hijoIzquierdo (arbolEcuacion a);

//PRECONDICION: el �rbol no es nulo
//Devolver un sub�rbol derecho
arbolEcuacion hijoDerecho (arbolEcuacion a);

//PRECONDICION: El arbol debe haberse inicializado anteriormente
//Precondici�n: El id de la nueva ecuaci�n no debe existir dentro del ABB
void insertarEcuacion (arbolEcuacion &a, ecuacion e);

//Precondici�n: El ABB de ecuaciones no debe estar vac�o
boolean existeIdEcuacion(arbolEcuacion a, strDinamico id);

//Precondici�n: El ABB no puede estar vac�o e id debe existir en el ABB
ecuacion obtenerEcuacionPorId(arbolEcuacion a, strDinamico id);


//Precondici�n: El ABB de ecuaciones no debe estar vac�o
void mostrarArbol(arbolEcuacion a);

void destruirArbol(arbolEcuacion &a);


#endif // ARBOLECUACION_H_INCLUDED
