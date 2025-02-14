#ifndef ECUACIONSEGUNDOGRADO_H_INCLUDED
#define ECUACIONSEGUNDOGRADO_H_INCLUDED

typedef struct {
    int primerCoeficiente;
    int segundoCoeficiente;
    int tercerCoeficiente;
} ecuacionSegundoGrado;

ecuacionSegundoGrado crearSegundoGrado (int primerCoeficiente, int segundoCoeficiente, int tercerCoeficiente);

#endif // ECUACIONSEGUNDOGRADO_H_INCLUDED
