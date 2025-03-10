#include "listaStrDinamico.h"

void crearListaStrings (listaStrDinamico &l)
{
    l = NULL;
}

void destruirListaStrings (listaStrDinamico &l)
{
    if(l != NULL){
        destruirListaStrings(l -> sig);
        delete l;
    }
}

//Precondici�n: La lista debe haberse inicializado anteriormente
void insBack (listaStrDinamico &l, strDinamico s)
{
    strDinamico sInsertar;
    strCrear(sInsertar);
    strCop(sInsertar, s);

    if(l!=NULL)
    {
        listaStrDinamico aux = l;
        while(aux -> sig != NULL)
        {
            aux = aux -> sig;
        }
        aux -> sig = new nodoLista;
        aux -> sig -> sig = NULL;
        aux -> sig -> info = sInsertar;
    }
    else
    {
        l = new nodoLista;
        l -> sig = NULL;
        l -> info = sInsertar;
    }
}

int cantidadParametros(listaStrDinamico l)
{
    if (l == NULL)
        return 0;
    else
        return 1 + cantidadParametros(l -> sig);
}

//Precondicion: p debe pertenecer a una posici�n con datos dentro de l
void obtenerParametroEnPosicion(listaStrDinamico l, int p, strDinamico & s)
{
    int x = 0;
    listaStrDinamico aux = l;

    while(x != p)
    {
        strCop(s, aux -> info);
        aux = aux -> sig;
        x++;
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

        eliminarEspaciosVaciosAlInicio(sSinEspacios, resto);
    }

    return l;
}

//PRECONDICION: La lista debe haberse inicializado anteriormente
void mostrarLista (listaStrDinamico l)
{
    while (l!=NULL)
    {
        strDinamico prueba;
        strCrear(prueba);
        strCop(prueba, l->info);

        print(l->info);
        printf("\n");

        l=l->sig;
    }
}
















