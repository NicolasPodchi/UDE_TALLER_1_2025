#include "1.Auxiliares/listaStrDinamico.h"
#include "2.Solucion/arbolEcuacion.h"

int main()
{
    arbolEcuacion arbolEcuaciones;
    crear(arbolEcuaciones);

    listaStrDinamico parametros;
    crearListaStrings(parametros);

    strDinamico instruccion;

    do
    {

        strDinamico comando;
        strCrear(comando);
        printf("Ingrese comando: ");
        scan(comando);
        parsing(comando, parametros);
        strDestruir(comando);

        strCrear(instruccion);
        if(cantidadParametros(parametros)>0)
        {
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
                    strDinamico paramId;
                    strCrear(paramId);
                    obtenerParametroEnPosicion(parametros,1,paramId);

                    if (validarStringAlfabetico(paramId) == FALSE)// param 1 debe ser alfabetico
                        printf("El ID de la ecuacion debe ser alfabetico");
                    else if (existeIdEcuacion(arbolEcuaciones, paramId) == TRUE)// el id de la ecuacion no puede existir en el arbol
                        printf("El ID de la ecuacion ya existe");
                    else
                    {
                        int i = 2;
                        boolean valido = TRUE;
                        do
                        {
                            strDinamico paramAux;
                            strCrear(paramAux);
                            obtenerParametroEnPosicion(parametros, i, paramAux);
                            valido = validarStringNumerico(paramAux);
                            strDestruir(paramAux);
                            i++;
                        }
                        while(i < cantParametros && valido == TRUE);

                        if(valido == FALSE)
                        {
                            printf("Los coeficientes deben ser valores numericos enteros");
                        }
                        else
                        {
                            strDinamico paramAux;
                            strCrear(paramAux);
                            obtenerParametroEnPosicion(parametros, 2, paramAux);

                            if(validarStringNumericoDistintoDeCero(paramAux) == FALSE)
                                printf("El coeficiente principal debe ser distinto de cero");
                            else
                            {
                                // CREAR
                                ecuacion nuevaEcuacion;

                                strDinamico idNuevaEcuacion;
                                strCrear(idNuevaEcuacion);
                                strCop(idNuevaEcuacion, paramId);

                                strDinamico paramCoef1;
                                strCrear(paramCoef1);
                                obtenerParametroEnPosicion(parametros,2,paramCoef1);
                                int primerCoeficiente = convertirStringAEntero(paramCoef1);
                                strDestruir(paramCoef1);

                                strDinamico paramCoef2;
                                strCrear(paramCoef2);
                                obtenerParametroEnPosicion(parametros,3,paramCoef2);
                                int segundoCoeficiente = convertirStringAEntero(paramCoef2);
                                strDestruir(paramCoef2);

                                if(cantParametros == 4)
                                {
                                    nuevaEcuacion = crearEcuacionPrimerGrado(idNuevaEcuacion, primerCoeficiente, segundoCoeficiente);
                                }
                                else
                                {
                                    strDinamico paramCoef3;
                                    strCrear(paramCoef3);
                                    obtenerParametroEnPosicion(parametros,4,paramCoef3);
                                    int tercerCoeficiente = convertirStringAEntero(paramCoef3);
                                    strDestruir(paramCoef3);

                                    nuevaEcuacion = crearEcuacionSegundoGrado(idNuevaEcuacion, primerCoeficiente, segundoCoeficiente, tercerCoeficiente);
                                }
                                printf("Resultado: ");
                                mostrarEcuacion(nuevaEcuacion);
                                insertarEcuacion(arbolEcuaciones, nuevaEcuacion);

                                strDestruir(idNuevaEcuacion);
                            }
                            strDestruir(paramAux);
                        }
                    }
                    strDestruir(paramId);
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
                    strDinamico paramId;
                    strCrear(paramId);
                    obtenerParametroEnPosicion(parametros, 1, paramId); //Validar que existe la primer ecuacion

                    if (validarStringAlfabetico(paramId) == FALSE)
                        printf("El ID de la ecuacion debe ser alfabetico");
                    else if(existeIdEcuacion(arbolEcuaciones, paramId)==FALSE)
                        printf("El ID ingresado no existe en memoria");
                    else
                    {
                        //FUNCIONALIDAD RESOLVER
                        ecuacion ecuacionResolver = obtenerEcuacionPorId(arbolEcuaciones, paramId);

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
                    strDestruir(paramId);
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
                        strDinamico paramId;
                        strCrear(paramId);
                        obtenerParametroEnPosicion(parametros, i, paramId);
                        if(validarStringAlfabetico(paramId) == TRUE) //Validar que todos los parametros sean strings
                            i++;
                        else
                            valido == FALSE;
                        strDestruir(paramId);
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
                    strDinamico paramId;
                    strCrear(paramId);
                    obtenerParametroEnPosicion(parametros,1,paramId);
                    if(validarStringAlfabetico(paramId) == FALSE) // validar tipo de parametros (ALFABETICO)
                    {
                        printf("El parametro debe ser un valor alfabetico");
                    }
                    else if(existeIdEcuacion(arbolEcuaciones, paramId) == FALSE) //ID NO PUEDE EXISTIR EN MEMORIA
                    {
                        printf("La ecuacion que intenta recuperar no existe en memoria");
                    }
                    else if(existeIdEcuacionArchivo(paramId) == TRUE) //DEBE EXISTIR EL ARCHIVO CON EL ID
                    {
                        printf("La ecuacion que intenta recuperar ya se encuentra almacenada");
                    }
                    else
                    {
                        // GUARDAR
                        ecuacion ecuacionGuardar = obtenerEcuacionPorId(arbolEcuaciones, paramId);
                        bajarEcuacion(ecuacionGuardar);

                        printf("Resultado: Ecuacion guardada con exito");
                    }
                    strDestruir(paramId);
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
                    strDinamico paramId;
                    strCrear(paramId);
                    obtenerParametroEnPosicion(parametros,1,paramId);
                    if(validarStringAlfabetico(paramId) == FALSE) // validar tipo de parametros (ALFABETICO)
                    {
                        printf("El parametro debe ser un valor alfab�tico");
                    }
                    else if(existeIdEcuacion(arbolEcuaciones, paramId) == TRUE) //ID NO PUEDE EXISTIR EN MEMORIA
                    {
                        printf("La ecuacion que intenta recuperar ya existe en memoria");
                    }
                    else if(existeIdEcuacionArchivo(paramId) == FALSE) //DEBE EXISTIR EL ARCHIVO CON EL ID
                    {
                        printf("La ecuacion que intenta recuperar no se encuentra almacenada");
                    }
                    else
                    {
                        // RECUPERAR
                        ecuacion ecuacionRecuperar;
                        levantarEcuacion(paramId, ecuacionRecuperar);
                        insertarEcuacion(arbolEcuaciones, ecuacionRecuperar);

                        printf("Resultado: Ecuacion recuperada con exito");
                    }
                    strDestruir(paramId);
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
                }
            }
            else
            {
                printf("COMANDO NO RECONOCIDO\n");
                system("pause");
            }

            //destruir lista de parametros
            destruirListaStrings(parametros);

            printf("\n");
        }
        else
        {
            printf("Debe ingresar un comando\n");
            system("pause");
        }

    }
    while (!strEq(instruccion, "salir") && (!strEq(instruccion, "SALIR")));

    strDestruir(instruccion);
}
