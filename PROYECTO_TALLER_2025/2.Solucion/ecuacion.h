#ifndef ECUACION_H_INCLUDED
#define ECUACION_H_INCLUDED

#include <cstdlib>

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

ecuacion crearEcuacionPrimerGrado(strDinamico id, int primerCoeficiente, int segundoCoeficiente);

ecuacion crearEcuacionSegundoGrado(strDinamico id, int primerCoeficiente, int segundCoeficiente, int tercerCoeficiente);

void mostrarEcuacion(ecuacion e);

void sumarDistintosGrados(ecuacion esg, ecuacion epg, ecuacion &nuevaEcuacion);

void sumarMismoGrado(ecuacion e1, ecuacion e2, ecuacion &nuevaEcuacion);

//Precondicion: e1 y e2 EXISTEN en el ABB de ecuaciones e id NO existe en el ABB
ecuacion sumarEcuaciones(ecuacion e1, ecuacion e2, strDinamico id);

void destruirEcuacion(ecuacion &e);

//Precondici�n: El archivo viene abierto para escritura
void bajarEcuacion (ecuacion e);

//Precondici�n: El archivo viene abierto para escritura
void levantarEcuacion (strDinamico id, ecuacion &e);

boolean existeIdEcuacionArchivo(strDinamico id);

#endif // ECUACION_H_INCLUDED
