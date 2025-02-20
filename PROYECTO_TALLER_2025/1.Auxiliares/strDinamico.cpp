#include "strDinamico.h"
#include <stdio.h>
void strcrear (strDinamico &s)
{
    s = new char[1];
    s[0]='\0';
}

void strdestruir(strDinamico &s)
{
    delete[]s;
    s = NULL;
}

int strlar (strDinamico s)
{
    int i=0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strcop (strDinamico &s1, strDinamico s2)
{
    delete[]s1;
    int largo = strlar(s2);
    s1 = new char[largo+1];
    int i =0;
    while(s2[i]!='\0')
    {
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
}

//LEER STRING
void scan(strDinamico &cadena)
{
    strcrear(cadena);

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
    strcop(cadena, cadenaAux);
    strdestruir(cadenaAux);
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

boolean streq (strDinamico s1, strDinamico s2)
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

boolean validarAlfabetico(strDinamico s)
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

//Precondición: s debe ser un string numerico
int convertirAEntero(strDinamico s)
{
    int i=0;
    int resultado = 0;
    while(s[i]!='\0')
    {

    }
}

//PRECONDICIÓN: El archivo viene abierto para escritura.
void bajar_string(strDinamico s, FILE * f)
{
    int i=0;
    while(s[i]!='\0')
    {
        fwrite(&s[i],sizeof(char),1,f);
        i++;
    }
    fwrite(&s[i],sizeof(char),1,f);
}

//PRECONDICIÓN: El archivo viene abierto para lectura.
void levantar_string(strDinamico &s,FILE * f)
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
    strcop(s,aux);
    strdestruir(aux);
}
