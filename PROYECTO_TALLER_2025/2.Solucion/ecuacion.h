#ifndef ECUACION_H_INCLUDED
#define ECUACION_H_INCLUDED

#include "../1.Auxiliares/strDinamico.h"
#include "tipoEcuacion.h"
#include "ecuacionPrimerGrado.h"
#include "ecuacionSegundoGrado.h"

typedef struct
{
    strDinamico id;
    tipoEcuacion discriminante;

    union
    {
        ecuacionPrimerGrado primerGrado;
        ecuacionSegundoGrado segundoGrado;

    } datos;

} ecuacion;

void getId(ecuacion e, strDinamico &s);

tipoEcuacion getTipo(ecuacion e);

ecuacionPrimerGrado getEcuacionPrimerGrado(ecuacion e);

ecuacionSegundoGrado getEcuacionSegundoGrado(ecuacion e);

void crearEcuacionPrimerGrado( ecuacion &e, strDinamico id, int primerCoeficiente, int segundoCoeficiente);

void crearEcuacionSegundoGrado(ecuacion &e, strDinamico id, int primerCoeficiente, int segundCoeficiente, int tercerCoeficiente);

void mostrarEcuacion(ecuacion e);

boolean existeIdEcuacionArchivo(strDinamico id, FILE * f);

//Precondicion: La ecuación debe existir en el ABB de ecuaciones
void resolverEcuacion(ecuacion e);

void mostrarEcuacion(ecuacion e);

//Precondicion: e1 y e2 EXISTEN en el ABB de ecuaciones e id NO existe en el ABB
ecuacion sumarEcuaciones(ecuacion e1, ecuacion e2, strDinamico id);

//Precondición: El archivo viene abierto para escritura
void bajarEcuacion (ecuacion e, FILE * f);

//Precondición: El archivo viene abierto para escritura
void levantarEcuacion (ecuacion &e, FILE * f);

#endif // ECUACION_H_INCLUDED
