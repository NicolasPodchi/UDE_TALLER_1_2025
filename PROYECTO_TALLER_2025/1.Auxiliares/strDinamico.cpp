#include <stdio.h>
#include "strDinamico.h"

void strCrear (strDinamico &s)
{
    s = new char[1];
    s[0]='\0';
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
    int i=0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strCop (strDinamico &s1, strDinamico s2)
{
    delete[]s1;
    int largo = strLar(s2);
    s1 = new char[largo+1];
    int i =0;
    while(s2[i]!='\0')
    {
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
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
    boolean esAlfabeitco = TRUE;
    int i=0;
    while(s[i]!='\0' && esAlfabeitco)
    {
        if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122)
            i++;
        else
            esAlfabeitco = FALSE;
    }
    return esAlfabeitco;
}

boolean validarStringNumerico(strDinamico s)
{
    boolean esNumerico = TRUE;
    int i=0;
    while(s[i]!='\0' && esNumerico)
    {
        if(s[i]>=48 && s[i]<=57)
            i++;
        else
            esNumerico = FALSE;
    }
    return esNumerico;
}

//Precondición: s no puede ser vacío ni tener espacios vacíos al principio y/o al final, debe ser un string numérico.
int convertirStringAEntero(strDinamico s)
{
    int i=0, resultado = 0;

    while(s[i]!='\0')
    {
        int nro = s[i] - 48;
        resultado =  (resultado * 10) + nro;

        i++;
    }
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
