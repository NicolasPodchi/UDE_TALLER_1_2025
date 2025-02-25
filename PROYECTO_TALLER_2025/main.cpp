#include "1.Auxiliares/listaStrDinamico.h"

int main()
{
    strDinamico s;
    strCrear(s);
    scan(s);

    strDinamico aux;
    strCrear(aux);

//    strCop(aux, s);
    eliminarEspaciosVaciosAlInicio(aux, s);

    strDinamico primerPalabra, resto;
    strCrear(primerPalabra);
    strCrear(resto);

    obtenerPrimerPalabra(primerPalabra, resto, aux);

    int coso = strLar(primerPalabra);
    printf(" \n cosooo %d ", coso);

    print(primerPalabra);

    int coso2 = strLar(resto);
    printf(" \n cosooo RESTOOO %d ", coso2);

    printf(" \n RESTO > \n");
     print(resto);
}
