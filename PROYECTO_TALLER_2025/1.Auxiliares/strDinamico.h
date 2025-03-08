#ifndef STRING_DINAMICO_H_INCLUDED
#define STRING_DINAMICO_H_INCLUDED

#include <stdio.h>
#include "boolean.h"

const int MAX = 80;
typedef char * strDinamico;

void strCrear (strDinamico &s);

void strDestruir(strDinamico &s);

void scan(strDinamico &cadena);

void print (strDinamico s);

int strLar (strDinamico s);

void strCop (strDinamico &s1, strDinamico s2);

boolean strEq (strDinamico s1, strDinamico s2);

//CONCATENAR SEGUNDO STRING AL FINAL DEL PRIMERO
void strCon(strDinamico &cadenaConcatenada, strDinamico cadena1, strDinamico cadena2);

//PRIMER STRING MENOR AL SEGUNDO
boolean strMen(strDinamico cadena1, strDinamico cadena2);

boolean validarStringAlfabetico(strDinamico s);

boolean validarStringNumerico(strDinamico s);

boolean validarStringNumericoDistintoDeCero(strDinamico s);

//Precondici�n: s no puede ser vac�o ni tener espacios vac�os al principio y/o al final, debe ser un string num�rico.
int convertirStringAEntero(strDinamico s);

//Precondici�n: s es un string alfabetico no vac�o.
void eliminarEspaciosVaciosAlInicio(strDinamico &s1, strDinamico s2);

int strLarPrimerPalabra (strDinamico s);

//Precondici�n: s es un string alfabetico no vac�o y el primer caracter no es un esp�cio.
void obtenerPrimerPalabra(strDinamico &s1, strDinamico &s2, strDinamico sEntrada);

//Precondici�n: El archivo viene abierto para escritura.
void bajarString(strDinamico s, FILE * f);

//Precondici�n: El archivo viene abierto para lectura.
void levantarString(strDinamico &s,FILE * f);

void convertirNombreArchivo(strDinamico &nombreArchivo, strDinamico id);

#endif // STRING_DINAMICO_H_INCLUDED
