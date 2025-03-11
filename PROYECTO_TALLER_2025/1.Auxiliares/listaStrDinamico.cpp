#include "listaStrDinamico.h"

void crearListaStrings (listaStrDinamico &l)
{
    l = NULL;
}

void destruirListaStrings (listaStrDinamico &l)
{
    if(l != NULL){
        destruirListaStrings(l -> sig);
        //strDestruir(l -> info);
        delete l;
        l = NULL;
    }

    /*while(l != NULL)
    {
        listaStrDinamico aux = l;
        l = aux -> sig;
        aux -> sig = NULL;

        if(aux -> info != NULL)
            strDestruir(aux -> info);

        delete aux;
    }*/
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
        //strCop(s, aux -> info);
        aux = aux -> sig;
        x++;
    }

    strCop(s, aux -> info);
}

void parsing(strDinamico s, listaStrDinamico &l)
{
    strDinamico sSinEspacios, primerPalabra, resto;
    strCrear(sSinEspacios);
    strCrear(primerPalabra);
    strCrear(resto);

    eliminarEspaciosVaciosAlInicio(sSinEspacios, s);

    while(strLar(sSinEspacios) != 0)
    {
        obtenerPrimerPalabra(primerPalabra, resto, sSinEspacios);
        insBack(l, primerPalabra);

        eliminarEspaciosVaciosAlInicio(sSinEspacios, resto);
    }

    strDestruir(sSinEspacios);
    strDestruir(primerPalabra);
    strDestruir(resto);
}

//PRECONDICION: La lista debe haberse inicializado anteriormente
void mostrarLista (listaStrDinamico l)
{
    while (l!=NULL)
    {
        print(l->info);
        printf("\n");

        l=l->sig;
    }
}
















