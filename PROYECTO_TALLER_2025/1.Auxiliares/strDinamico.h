#ifndef STRING_DINAMICO_H_INCLUDED
#define STRING_DINAMICO_H_INCLUDED
#include "boolean.h"
#include <stdio.h>
const int MAX = 80;
typedef char * strDinamico;

void strcrear (strDinamico &s);

void strdestruir(strDinamico &s);

void scan(strDinamico &s);

void print (strDinamico s);

int strlar (strDinamico s);

void strcop (strDinamico &s1, strDinamico s2);

boolean streq (strDinamico s1, strDinamico s2);

boolean validarAlfabetico(strDinamico s);

boolean validarStringNumerico(strDinamico s);

//Precondición: s debe ser un string numerico
int convertirAEntero(strDinamico s);

//Precondición: El archivo viene abierto para escritura
void bajarString(strDinamico s, FILE * f);

//Precondición: El archivo viene abierto para escritura
void levantarString(strDinamico &s,FILE * f);

#endif // STRING_DINAMICO_H_INCLUDED
