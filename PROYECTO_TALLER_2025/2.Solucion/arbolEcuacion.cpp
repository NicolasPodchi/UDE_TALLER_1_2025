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
    if (a==NULL)
    {
        a=new nodoArbol;
        a->info=e;
        a->hIzq=NULL;
        a->hDer=NULL;
    }
    else
    {
        strDinamico strAux1, strAux2;
        strCrear(strAux1);
        strCrear(strAux2);
        getId(a->info, strAux1);
        getId(e, strAux2);

        if(strMen(strAux2, strAux1) == TRUE)
        {
            strDestruir(strAux1);
            strDestruir(strAux2);
            insertarEcuacion(a->hIzq,e);
        }
        else
        {
            strDestruir(strAux1);
            strDestruir(strAux2);
            insertarEcuacion(a->hDer,e);
        }
    }
}

//Precondici�n: El ABB de ecuaciones no debe estar vac�o
boolean existeIdEcuacion(arbolEcuacion a, strDinamico id)
{
    boolean encontre = FALSE;

    while(a!=NULL && !encontre)
    {
        strDinamico strAux;
        strCrear(strAux);
        getId(a->info, strAux);

        if (strEq(strAux, id))
            encontre = TRUE;
        else
        {
            if (strMen(id, strAux) == TRUE)
                a=a -> hIzq;
            else
                a=a -> hDer;
        }
        strDestruir(strAux);
    }
    return encontre;
}

//Precondici�n: El ABB no puede estar vac�o e id debe existir en el ABB
ecuacion obtenerEcuacionPorId(arbolEcuacion a, strDinamico id)
{
    boolean encontre = FALSE;
    while(a != NULL && !encontre)
    {
        strDinamico strAux;
        strCrear(strAux);
        getId(a -> info, strAux);

        if (strEq(strAux, id))
            encontre = TRUE;
        else
        {
            if(strMen(id, strAux))
                a = a -> hIzq;
            else
                a = a -> hDer;
        }
        strDestruir(strAux);
    }

    return a -> info;
}


//Precondici�n: El ABB de ecuaciones no debe estar vac�o
void mostrarArbol(arbolEcuacion a)
{
    if(a != NULL)
    {
        mostrarArbol(a ->hIzq);
        mostrarEcuacion(a->info);
        printf("\n");
        mostrarArbol(a ->hDer);
    }
}

void destruirArbol(arbolEcuacion &a)
{
    if(a != NULL)
    {
        destruirArbol(a ->hIzq);
        destruirArbol(a ->hDer);
        destruirEcuacion(a -> info);
        delete a;
        a = NULL;
    }
}

