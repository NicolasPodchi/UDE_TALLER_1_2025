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
        crearListaStrings(parametros);

        printf("Ingrese comando: ");
        scan(comando);
        parsing(comando, parametros);
        obtenerParametroEnPosicion(parametros, 0, instruccion);

        if(strEq(instruccion, "crear")||strEq(instruccion, "CREAR")) ////////////////////////////////////////////////////////////////////// CREAR
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
                else if (existeIdEcuacion(arbolEcuaciones, param) == TRUE)// el id de la ecuacion no puede existir en el arbol
                    printf("El ID de la ecuacion ya existe");
                else
                {
                    int i = 2;
                    boolean valido = TRUE;
                    do
                    {
                        obtenerParametroEnPosicion(parametros, i, param);
                        valido = validarStringNumerico(param);

                        i++;
                    }
                    while(i < cantParametros && valido == TRUE);

                    if(valido == FALSE)
                    {
                        printf("Los coeficientes deben ser valores numericos enteros");
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
                            printf("Resultado: ");
                            mostrarEcuacion(nuevaEcuacion);
                            insertarEcuacion(arbolEcuaciones, nuevaEcuacion);

                            strDestruir(idNuevaEcuacion);
                        }
                    }
                }
            }
        }
        else if(strEq(instruccion, "mostrar")||(strEq(instruccion, "MOSTRAR"))) ////////////////////////////////////////////////////////////////////// MOSTRAR //////////
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
                    printf("Resultado: \n");
                mostrarArbol(arbolEcuaciones);
            }
        }
        else if(strEq(instruccion, "resolver")||(strEq(instruccion, "RESOLVER"))) ////////////////////////////////////////////////////////////////////// RESOLVER //////////
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 2)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                obtenerParametroEnPosicion(parametros, 1, param); //Validar que existe la primer ecuacion

                if (validarStringAlfabetico(param) == FALSE)
                    printf("El ID de la ecuacion debe ser alfabetico");
                else if(existeIdEcuacion(arbolEcuaciones, param)==FALSE)
                    printf("El ID ingresado no existe en memoria");
                else
                {
                    //FUNCIONALIDAD RESOLVER
                    ecuacion ecuacionResolver = obtenerEcuacionPorId(arbolEcuaciones, param);

                    if(getTipo(ecuacionResolver) == PRIMER_GRADO)
                    {
                        float resultado = resolverPrimerGrado(getEcuacionPrimerGrado(ecuacionResolver));
                        printf("Resultado: x = %.2f\n", resultado);
                    }
                    else
                    {
                        float discriminante = resolverDiscriminante(getEcuacionSegundoGrado(ecuacionResolver));

                        if (discriminante < 0)
                            printf("La ecuacion no tiene solucion");
                        else if (discriminante > 0)
                        {
                            float resultado1, resultado2;
                            resolverEcuacionDeDosResultados(getEcuacionSegundoGrado(ecuacionResolver), discriminante, resultado1, resultado2);
                            printf("Resultado: x1 = %.2f / x2 = %.2f\n", resultado1, resultado2);
                        }
                        else
                        {
                            float resultado = resolverEcuacionDeUnSoloResultado (getEcuacionSegundoGrado(ecuacionResolver));
                            printf("Resultado: x = %.2f\n", resultado);
                        }
                    }
                }
            }
        }
        else if(strEq(instruccion, "sumar")||(strEq(instruccion, "SUMAR"))) ////////////////////////////////////////////////////////////////////// SUMAR //////////
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 4)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                int i = 1;
                boolean valido = TRUE;
                do
                {
                    obtenerParametroEnPosicion(parametros, i, param);
                    if(validarStringAlfabetico(param) == TRUE) //Validar que todos los parametros sean strings
                        i++;
                    else
                        valido == FALSE;
                }
                while(i < 4 && valido == TRUE);

                if(valido == FALSE)
                {
                    printf("El ID de las ecuaciones debe ser alfabetico");
                }
                else
                {
                    strDinamico idUno, idDos, idTres;
                    strCrear(idUno);
                    strCrear(idDos);
                    strCrear(idTres);

                    obtenerParametroEnPosicion(parametros, 1, idUno); //Validar que existe la primer ecuacion
                    if(existeIdEcuacion(arbolEcuaciones, idUno)==FALSE)
                    {
                        printf("El primer ID no existe");
                    }
                    else
                    {
                        obtenerParametroEnPosicion(parametros, 2, idDos); //Validar que existe la segunda ecuacion
                        if(existeIdEcuacion(arbolEcuaciones, idDos)==FALSE)
                        {
                            printf("El segundo ID no existe");
                        }
                        else
                        {
                            obtenerParametroEnPosicion(parametros, 3, idTres); //Validar que NO existe el ID para la nueva ecuacion
                            if(existeIdEcuacion(arbolEcuaciones,idTres)==TRUE)
                            {
                                printf("El nuevo ID ingresado ya existe");
                            }
                            else
                            {
                                ecuacion ecuacionUno = obtenerEcuacionPorId(arbolEcuaciones,idUno);
                                ecuacion ecuacionDos = obtenerEcuacionPorId(arbolEcuaciones,idDos);

                                ecuacion ecuacionResultado = sumarEcuaciones(ecuacionUno, ecuacionDos, idTres);

                                if(getTipo(ecuacionResultado) == PRIMER_GRADO && getPrimerCoeficiente(getEcuacionPrimerGrado(ecuacionResultado)) == 0)
                                {
                                    printf("Suma invalida, el resultado no puede ser un termino independiente");
                                }
                                else
                                {
                                    mostrarEcuacion(ecuacionResultado);
                                    insertarEcuacion(arbolEcuaciones, ecuacionResultado);
                                }
                            }
                        }
                    }

                    strDestruir(idUno);
                    strDestruir(idDos);
                    strDestruir(idTres);
                }
            }
        }
        else if(strEq(instruccion, "guardar")||(strEq(instruccion, "GUARDAR"))) ////////////////////////////////////////////////////////////////////// GUARDAR //////////
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
                    printf("El parametro debe ser un valor alfabetico");
                }
                else if(existeIdEcuacion(arbolEcuaciones, param) == FALSE) //ID NO PUEDE EXISTIR EN MEMORIA
                {
                    printf("La ecuacion que intenta recuperar no existe en memoria");
                }
                else if(existeIdEcuacionArchivo(param) == TRUE) //DEBE EXISTIR EL ARCHIVO CON EL ID
                {
                    printf("La ecuacion que intenta recuperar ya se encuentra almacenada");
                }
                else
                {
                    // GUARDAR
                    ecuacion ecuacionGuardar = obtenerEcuacionPorId(arbolEcuaciones, param);
                    bajarEcuacion(ecuacionGuardar);

                    printf("Resultado: Ecuacion guardada con exito");
                }
            }
        }
        else if(strEq(instruccion, "recuperar")||(strEq(instruccion, "RECUPERAR"))) ////////////////////////////////////////////////////////////////////// RECUPERAR //////////
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
                    printf("El parametro debe ser un valor alfab�tico");
                }
                else if(existeIdEcuacion(arbolEcuaciones, param) == TRUE) //ID NO PUEDE EXISTIR EN MEMORIA
                {
                    printf("La ecuacion que intenta recuperar ya existe en memoria");
                }
                else if(existeIdEcuacionArchivo(param) == FALSE) //DEBE EXISTIR EL ARCHIVO CON EL ID
                {
                    printf("La ecuacion que intenta recuperar no se encuentra almacenada");
                }
                else
                {
                    // RECUPERAR
                    ecuacion ecuacionRecuperar;
                    levantarEcuacion(param, ecuacionRecuperar);
                    insertarEcuacion(arbolEcuaciones, ecuacionRecuperar);

                    printf("Resultado: Ecuacion recuperada con exito");
                }
            }
        }
        else if(strEq(instruccion, "salir")||(strEq(instruccion, "SALIR"))) ////////////////////////////////////////////////////////////////////// SALIR //////////
        {
            //validar cantidad de parametros
            if(cantidadParametros(parametros) != 1)
            {
                printf("Cantidad de parametros incorrecta");
            }
            else
            {
                //destruir arbol de ecuaciones
                destruirArbol(arbolEcuaciones);

                //destruir strings
                strDestruir(comando);
                strDestruir(param);
            }
        }
        else
        {
            printf("COMANDO NO RECONOCIDO\n");
            system("pause");
        }

        //destruir lista de parametros
        //destruirListaStrings(parametros);

        mostrarLista(parametros);
        int cantidadParametroAux = cantidadParametros(parametros);
        printf("\n  CANTIDAD PARAMETROSS >> %d", cantidadParametroAux);

        printf("\n");
    }
    while (!strEq(instruccion, "salir") && (!strEq(instruccion, "SALIR")));

    strDestruir(instruccion);
}
