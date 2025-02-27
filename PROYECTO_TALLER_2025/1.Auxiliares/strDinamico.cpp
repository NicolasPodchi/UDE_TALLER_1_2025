#include <stdio.h>
#include "strDinamico.h"

void strCrear (strDinamico &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strDestruir(strDinamico &s)
{
    delete[]s;
    s = NULL;
}

void scan(strDinamico &cadena)
{
    strCrear(cadena);

    strDinamico cadenaAux;
    cadenaAux = new char [MAX];

    int i = 0;
    char c;

    fflush(stdin);
    scanf("%c", &c);

    while(i < MAX-1&& c != '\n')
    {
        cadenaAux[i] = c;
        scanf("%c", &c);
        i++;
    }
    cadenaAux[i] = '\0';
    strCop(cadena, cadenaAux);
    strDestruir(cadenaAux);
}

void print (strDinamico s)
{
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

int strLar (strDinamico s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strCop (strDinamico &s1, strDinamico s2)
{
    delete[]s1;
    int largo = strLar(s2);
    s1 = new char[largo+1];
    int i = 0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

boolean strEq (strDinamico s1, strDinamico s2)
{
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;

}

boolean validarStringAlfabetico(strDinamico s)
{
    boolean esAlfabetico = TRUE;
    int i=0;
    while(s[i]!='\0' && esAlfabetico)
    {
        if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            i++;
        else
            esAlfabetico = FALSE;
    }
    return esAlfabetico;
}

boolean validarStringNumerico(strDinamico s)
{
    boolean esNumerico = TRUE;
    int i=0;
    while(s[i]!='\0' && esNumerico)
    {
        if((s[i] >= 48 && s[i] <= 57) || (i == 0 && s[i] == 45))
            i++;
        else
            esNumerico = FALSE;
    }
    return esNumerico;
}

//Precondición: s no puede ser vac�o ni tener espacios vac�os al principio y/o al final, debe ser un string num�rico.
int convertirStringAEntero(strDinamico s)
{
    int i = 0, resultado = 0;
    boolean negativo = FALSE;

    while(s[i]!='\0')
    {
        if(s[i] != 45)
        {
            int nro = s[i] - 48;
            resultado =  (resultado * 10) + nro;
        }
        else
        {
            negativo = TRUE;
        }

        i++;
    }

    if(negativo == TRUE)
        return resultado * -1;
    else
        return resultado;
}

//Precondición: s2 es un string alfabetico no vacío.
void eliminarEspaciosVaciosAlInicio(strDinamico &s1, strDinamico s2)
{
    delete[]s1;
    int i = 0, iInsertar = 0; // i UTILIZADO PARA RECORRER s2, iInsertar utilizado para inserción en s1
    boolean espacioEliminado = FALSE;

    while(s2[i] != '\0')
    {
        if(espacioEliminado == TRUE || s2[i] != 32)
        {
            if(espacioEliminado == FALSE)
            {
                s1 = new char[(strLar(s2) - i) + 1];
                espacioEliminado = TRUE;
            }

            s1[iInsertar] = s2[i];
            iInsertar++;
        }

        i++;
    }
    
    if(espacioEliminado == FALSE)
        s1 = new char[1];

    s1[iInsertar] = '\0';
}

int strLarPrimerPalabra (strDinamico s)
{
    int i = 0;
    while (s[i] != '\0' && s[i] != 32)
        i++;
    return i;
}

//Precondición: s es un string alfabetico no vacío y el primer caracter no es un espácio.
void obtenerPrimerPalabra(strDinamico &s1, strDinamico &s2, strDinamico sEntrada)
{
    delete[]s1;
    delete[]s2;

    int largoPrimerPalabra = strLarPrimerPalabra(sEntrada);// CANTIDAD DE CARACTERES DE LA PRIMER PALABRA DE sEntrada
    s1 = new char[largoPrimerPalabra + 1];// CANTIDAD DE CARACTERES DE LA PRIMER PALABRA DE sEntrada + 1 PARA EL CARACTER NULO
    s2 = new char[(strLar(sEntrada) - largoPrimerPalabra) + 1];// CANTIDAD DE CARACTERES QUE OCUPA EL RESTO DEL STRING + 1 PARA EL CARACTER NULO

    int i = 0, iInsertar = 0; // i UTILIZADO PARA RECORRER sEntrada, iInsertar utilizado para inserción en s1 y s2
    boolean resto = FALSE;

    while(sEntrada[i] != '\0')
    {
        if(resto == FALSE)
        {
            s1[iInsertar] = sEntrada[i];

            // SI EL CARACTER QUE ACABO DE INSERTAR, FUE EL ULTIMO DE LA PRIMER PALABRA, PASO AL RESTO
            if(iInsertar == largoPrimerPalabra - 1)
            {
                s1[iInsertar + 1] = '\0';
                resto = TRUE;
                iInsertar = -1;
            }
        }
        else
        {
            s2[iInsertar] = sEntrada[i];
        }

        i++;
        iInsertar++;
    }

    s2[iInsertar] = '\0';
}

//Precondición: El archivo viene abierto para escritura.
void bajarString(strDinamico s, FILE * f)
{
    int i=0;
    while(s[i]!='\0')
    {
        fwrite(&s[i],sizeof(char),1,f);
        i++;
    }
    fwrite(&s[i],sizeof(char),1,f);
}

//Precondición: El archivo viene abierto para lectura.
void levantarString(strDinamico &s,FILE * f)
{
    int i = 0;
    strDinamico aux = new char[MAX];
    char c;
    fread(&c,sizeof(char),1,f);
    while(c!='\0' && !feof(f))
    {
        aux[i]=c;
        fread(&c,sizeof(char),1,f);
        i++;
    }
    aux[i]='\0';
    strCop(s,aux);
    strDestruir(aux);
}
