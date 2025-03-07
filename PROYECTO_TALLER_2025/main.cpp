#include "1.Auxiliares/listaStrDinamico.h"
#include "2.Solucion/arbolEcuacion.h"

int main()
{
    arbolEcuacion arbolEcuaciones;
    crear(arbolEcuaciones);

    listaStrDinamico parametros;
    strDinamico comando, instruccion;

    strCrear(comando);
    strCrear(instruccion);

    do
    {
        scan(comando);
        parametros = parsing(comando);
        obtenerParametroEnPosicion(parametros, 0, instruccion);

        if(strEq(instruccion, "crear"))
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) < 4 || cantidadParametros(parametros) > 5)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                // validar tipo de parametros (numerico alfabetico)
                    // param 1 debe ser alfabetico
                    // para 2, 3 y 4 debe ser numerico

                //validaciones crear
                    // el id de la ecuacion no puede existir en el arbol
                    // el primer coeficiente debe ser distinto de 0

                //FUNCIONALIDAD CREAR

                printf("crear");
            }
        }
        else if(strEq(instruccion, "mostrar"))
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 1)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                printf("mostrar");
                // validar tipo de parametros (numerico alfabetico)
                //validaciones crear
                //FUNCIONALIDAD MOSTRAR
            }
        }
        else if(strEq(instruccion, "resolver"))
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 2)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                printf("resolver");
                // validar tipo de parametros (numerico alfabetico)
                //validaciones crear
                //FUNCIONALIDAD RESOLVER
            }
        }
        else if(strEq(instruccion, "sumar"))
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 4)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                printf("sumar");
                // validar tipo de parametros (numerico alfabetico)
                //validaciones crear
                //FUNCIONALIDAD sumar
            }
        }
        else if(strEq(instruccion, "guardar"))
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 2)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                printf("guardar");
                // validar tipo de parametros (numerico alfabetico)
                //validaciones crear
                //FUNCIONALIDAD guardar
            }
        }
        else if(strEq(instruccion, "recuperar"))
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 2)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                printf("recuperar");
                // validar tipo de parametros (numerico alfabetico)
                //validaciones crear
                //FUNCIONALIDAD recuperar
            }
        }
        else if(strEq(instruccion, "salir"))
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 1)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                //LIBERAR ESPACIO EN MEMORIA
                printf("salir");
            }
        }
        else
        {
            system("cls");
            printf("COMANDO NO RECONOCIDO \n");
            system("pause");
        }
    }
    while (strEq(instruccion, "salir") == FALSE);
}
