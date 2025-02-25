#include <stdio.h>
#include "listaStrDinamico.h"

void crearListaStrings (listaStrDinamico &l)
{
    l = NULL;
}

//Precondición: La lista debe haberse inicializado anteriormente
void insBack (listaStrDinamico &l, strDinamico s)
{
    if(l!=NULL)
    {
        listaStrDinamico aux = l;
        while(aux -> sig != NULL)
        {
            aux = aux -> sig;
        }
        aux -> sig = new nodoLista;
        aux -> sig -> sig = NULL;
        aux -> sig -> info = s;
    }
    else
    {
        l = new nodoLista;
        l -> sig = NULL;
        l -> info = s;
    }
}

int cantidadParametros(listaStrDinamico l)
{
    if (l == NULL)
        return 0;
    else
        return 1 + cantidadParametros(l -> sig);
}

//Precondición: p debe pertenecer a una posición con datos dentro de l
void obtenerParametroEnPosicion(listaStrDinamico l, int p, strDinamico & s)
{
    int i = 0;
    listaStrDinamico aux = l;

    while(i != p)
    {
        aux = aux -> sig;
    }

    strCop(s, aux -> info);
}

listaStrDinamico parsing(strDinamico s)
{
    strDinamico sSinEspacios, primerPalabra, resto;

    listaStrDinamico l;
    crearListaStrings(l);

    eliminarEspaciosVaciosAlInicio(sSinEspacios, s);

    while(strLar(sSinEspacios) != 0)
    {
        obtenerPrimerPalabra(primerPalabra, resto, sSinEspacios);
        insBack(l, primerPalabra);

        eliminarEspaciosVaciosAlInicio(sSinEspacios, s);
    }

    return l;
}
















