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
                obtenerParametroEnPosicion(parametros,1,instruccion);// validar tipo de parametros (numerico alfabetico) validaarstringalfabetico )parametro numero 1 que seria el id
                if (!validarStringAlfabetico(instruccion))
                    printf("El ID debe ser alfabetico");// param 1 debe ser alfabetico
                else
                {
                    obtenerParametroEnPosicion(parametros,2,instruccion);
                    if (validarStringNumerico(instruccion)==TRUE)
                    {
                        obtenerParametroEnPosicion(parametros,3,instruccion);
                        if (validarStringNumerico(instruccion)==TRUE)
                        {
                            obtenerParametroEnPosicion(parametros, 4, instruccion);
                            if (validarStringNumerico(instruccion)) // para 2, 3 y 4 debe ser numérico
                            {
                                obtenerParametroEnPosicion(parametros,1,instruccion);
                                if (!existeIdEcuacion(arbolEcuaciones,instruccion)) // el id de la ecuacion no puede existir en el arbol
                                //validaciones crear
                                // el primer coeficiente debe ser distinto de 0
                            }
                        }

                }
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
                if(arbolVacio==FALSE)
                {
                    printf("No existen ecuaciones para mostrar.");
                }
                else
                    mostrarArbol(arbolEcuaciones);
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
                int i = 1;
                boolean esAlfabetico=TRUE;;
                do
                {
                    obtenerParametroEnPosicion(parametros,i,instruccion);// validar tipo de parametros (numerico alfabetico) validaarstringalfabetico )parametro numero 1 que seria el id
                    if(validarStringAlfabetico(instruccion)==TRUE)
                        i++;
                    else
                        esAlfabetico==FALSE;
                }while(i<5 && esAlfabetico==TRUE);
                if(esAlfabetico)




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
