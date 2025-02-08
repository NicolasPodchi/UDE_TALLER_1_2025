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

#endif // ECUACION_H_INCLUDED
