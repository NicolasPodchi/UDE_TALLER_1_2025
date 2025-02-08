#ifndef STRING_DINAMICO_H_INCLUDED
#define STRING_DINAMICO_H_INCLUDED
#include "boolean.h"
#include <stdio.h>
const int MAX = 80;
typedef char * strings;

void strcrear (strings &s);

void scan(strings &s);

void print (strings s);

void strdestruir(strings &s);

void strcop (strings &s1, strings s2);

int strlar (strings s);

void strcon(strings &s1, strings s2);

void strswp (strings &s1, strings s2);

boolean strmen (strings s1, strings s2);

boolean streq (strings s1, strings s2);

//PRECONDICION: El archivo viene abierto para escritura
void bajar_string(strings s, FILE * f);

//PRECONDICIÓN: El archivo viene abierto para lectura.
void levantar_string(strings &s,FILE * f);

#endif // STRING_DINAMICO_H_INCLUDED
