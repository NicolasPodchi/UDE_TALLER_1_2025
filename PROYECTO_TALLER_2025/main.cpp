#include "1.Auxiliares/listaStrDinamico.h"
#include "2.Solucion/arbolEcuacion.h"

int main()
{
    arbolEcuacion arbolEcuaciones;
    crear(arbolEcuaciones);

    listaStrDinamico parametros;
    strDinamico comando, instruccion, param;

    strCrear(comando);
    strCrear(instruccion);
    strCrear(param);

    do
    {
        scan(comando);
        crearListaStrings(parametros);
        parametros = parsing(comando);
        obtenerParametroEnPosicion(parametros, 0, instruccion);

        if(strEq(instruccion, "crear")) ////////////////////////////////////////////////////////////////////// CREAR
        {
            //validar cantidad de parametros
            int cantParametros = cantidadParametros(parametros);

            if(cantParametros < 4 || cantParametros > 5)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                // validar tipo de parametros (numerico alfabetico) validaarstringalfabetico ) parametro numero 1 que seria el id
                obtenerParametroEnPosicion(parametros,1,param);

                if (validarStringAlfabetico(param) == FALSE)// param 1 debe ser alfabetico
                    printf("El ID de la ecuacion debe ser alfabetico");
//                else if (existeIdEcuacion(arbolEcuaciones, param) == TRUE)// el id de la ecuacion no puede existir en el arbol
//                    printf("El ID de la ecuación ya existe");
                else
                {
                //    mostrarLista(parametros);

                    int i = 2;
                    boolean valido = TRUE;
                    do
                    {
                        obtenerParametroEnPosicion(parametros, i, param);
                        if(validarStringNumerico(param) == FALSE)// validar tipo de parametros (numerico alfabetico)
                        {
                            valido == FALSE;
                        }

                        i++;
                    }
                    while(i < cantParametros && valido == TRUE);

                    if(valido == FALSE)
                    {
                        printf("Los coeficientes deben ser valores numéricos");
                    }
                    else
                    {
                        obtenerParametroEnPosicion(parametros, 2, param);

                        if(validarStringNumericoDistintoDeCero(param) == FALSE)
                            printf("El coeficiente principal debe ser distinto de cero");
                        else
                        {
                            // CREAR
                            ecuacion nuevaEcuacion;

                            strDinamico idNuevaEcuacion;
                            strCrear(idNuevaEcuacion);
                            obtenerParametroEnPosicion(parametros,1,idNuevaEcuacion);

                            obtenerParametroEnPosicion(parametros,2,param);
                            int primerCoeficiente = convertirStringAEntero(param);

                            obtenerParametroEnPosicion(parametros,3,param);
                            int segundoCoeficiente = convertirStringAEntero(param);

                            if(cantParametros == 4)
                            {
                                nuevaEcuacion = crearEcuacionPrimerGrado(idNuevaEcuacion, primerCoeficiente, segundoCoeficiente);
                            }
                            else
                            {
                                obtenerParametroEnPosicion(parametros,4,param);
                                int tercerCoeficiente = convertirStringAEntero(param);

                                nuevaEcuacion = crearEcuacionSegundoGrado(idNuevaEcuacion, primerCoeficiente, segundoCoeficiente, tercerCoeficiente);
                            }

                            insertarEcuacion(arbolEcuaciones, nuevaEcuacion);
                        }
                    }
                }
            }
        }
        else if(strEq(instruccion, "mostrar")) ////////////////////////////////////////////////////////////////////// MOSTRAR //////////
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 1)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                if(arbolVacio(arbolEcuaciones) == TRUE)
                {
                    printf("No existen ecuaciones para mostrar");
                }
                else
                    mostrarArbol(arbolEcuaciones);
            }
        }
        else if(strEq(instruccion, "resolver")) ////////////////////////////////////////////////////////////////////// RESOLVER //////////
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
        else if(strEq(instruccion, "sumar")) ////////////////////////////////////////////////////////////////////// SUMAR //////////
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
                boolean valido = TRUE;
                do
                {
                    // validar tipo de parametros (numerico alfabetico) validaarstringalfabetico )parametro numero 1 que seria el id
                    obtenerParametroEnPosicion(parametros, i, param);
                    if(validarStringAlfabetico(param) == TRUE)
                        i++;
                    else
                        valido == FALSE;
                }
                while(i < 5 && valido == TRUE);

                if(valido == FALSE)
                {
                    //MENSAJE DE ERROR
                }
                else
                {
                    //validaciones crear
                    //FUNCIONALIDAD sumar
                }
            }
        }
        else if(strEq(instruccion, "guardar")) ////////////////////////////////////////////////////////////////////// GUARDAR //////////
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 2)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                obtenerParametroEnPosicion(parametros,1,param);
                if(validarStringAlfabetico(param) == FALSE) // validar tipo de parametros (ALFABETICO)
                {
                    printf("El parametro debe ser un valor alfabético");
                }
                else if(existeIdEcuacion(arbolEcuaciones, param) == FALSE) //ID NO PUEDE EXISTIR EN MEMORIA
                {
                    printf("La ecuación que intenta recuperar no existe en memoria");
                }
                else if(existeIdEcuacionArchivo(param) == TRUE) //DEBE EXISTIR EL ARCHIVO CON EL ID
                {
                    printf("La ecuación que intenta recuperar ya se encuentra almacenada");
                }
                else
                {
                    // GUARDAR
                    ecuacion ecuacionGuardar = obtenerEcuacionPorId(arbolEcuaciones, param);
                    bajarEcuacion(ecuacionGuardar);

                    printf("Ecuación guardada existosamente");
                }
            }
        }
        else if(strEq(instruccion, "recuperar")) ////////////////////////////////////////////////////////////////////// RECUPERAR //////////
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 2)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                obtenerParametroEnPosicion(parametros,1,param);
                if(validarStringAlfabetico(param) == FALSE) // validar tipo de parametros (ALFABETICO)
                {
                    printf("El parametro debe ser un valor alfabético");
                }
                else if(existeIdEcuacion(arbolEcuaciones, param) == TRUE) //ID NO PUEDE EXISTIR EN MEMORIA
                {
                    printf("La ecuación que intenta recuperar ya existe en memoria");
                }
                else if(existeIdEcuacionArchivo(param) == FALSE) //DEBE EXISTIR EL ARCHIVO CON EL ID
                {
                    printf("La ecuación que intenta recuperar no se encuentra almacenada");
                }
                else
                {
                    // RECUPERAR
                    ecuacion ecuacionRecuperar;
                    levantarEcuacion(param, ecuacionRecuperar);
                    insertarEcuacion(arbolEcuaciones, ecuacionRecuperar);

                    printf("Ecuación recuperada existosamente");
                }
            }
        }
        else if(strEq(instruccion, "salir")) ////////////////////////////////////////////////////////////////////// SALIR //////////
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
            printf("COMANDO NO RECONOCIDO");
            system("pause");
        }

        printf("\n");
    }
    while (strEq(instruccion, "salir") == FALSE);
}
