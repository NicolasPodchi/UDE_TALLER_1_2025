#include "arbolEcuacion.h"

void crear (arbolEcuacion &a)
{
    a = NULL;
}

//PRECONDICION: El arbol debe haberse inicializado anteriormente
//Saber si un �rbol est� vac�o
boolean arbolVacio(arbolEcuacion a)
{
    boolean es = TRUE;
    if (a != NULL)
        es = FALSE;

    return es;
}


//PRECONDICION: el �rbol no es nulo
//Obtener la ra�z del �rbol
ecuacion darRaiz (arbolEcuacion a)
{
    return a->info;
}

//PRECONDICION: el �rbol no es nulo
//Devolver un sub�rbol izquierdo
arbolEcuacion hijoIzquierdo (arbolEcuacion a)
{
    return a->hIzq;
}

//PRECONDICION: el �rbol no es nulo
//Devolver un sub�rbol derecho
arbolEcuacion hijoDerecho (arbolEcuacion a)
{
    return a->hDer;
}

//PRECONDICION: El arbol debe haberse inicializado anteriormente
//Precondici�n: El id de la nueva ecuaci�n no debe existir dentro del ABB
void insertarEcuacion (arbolEcuacion &a, ecuacion e)
{
    strDinamico strAux1, strAux2;

    if (a==NULL)
    {
        a=new nodoArbol;
        a->info=e;
        a->hIzq=NULL;
        a->hDer=NULL;
    }
    else
    {
        getId(a->info, strAux1);
        getId(e, strAux2);

        if(strAux1 > strAux2)
        {
            insertarEcuacion(a->hIzq,e);
        }
        else
            insertarEcuacion(a->hDer,e);
    }
}

//Precondici�n: El ABB de ecuaciones no debe estar vac�o
boolean existeIdEcuacion(arbolEcuacion a, strDinamico id)
{
    boolean encontre = FALSE;
    strDinamico strAux;

    while(a!=NULL && !encontre)
    {
        getId(a->info, strAux);

        if (id == strAux)
            encontre = TRUE;
        else
        {
            if (id < strAux)
                a=a -> hIzq;
            else
                a=a -> hDer;
        }
    }
    return encontre;
}

//Precondici�n: El ABB no puede estar vac�o e id debe existir en el ABB
arbolEcuacion obtenerEcuacionPorId(arbolEcuacion a, strDinamico id)
{
    strDinamico strAux;

    getId(a -> info, strAux);
    while(a != NULL && strAux != id)
    {
        if(id < strAux)
            a = a -> hIzq;
        else
            a = a -> hDer;

        getId(a -> info, strAux);
    }

    return a;
}


//Precondici�n: El ABB de ecuaciones no debe estar vac�o
void mostrarArbol(arbolEcuacion a)
{
    if(a != NULL)
    {
        mostrarArbol(a ->hIzq);
        mostrarEcuacion(a->info);
        mostrarArbol(a ->hDer);
    }
}

void destruirArbol(arbolEcuacion &a);

