#include <stdio.h>
#include <cctype>
#include "strDinamico.h"

void strCrear (strDinamico &s)
{
    s = new char[1];
    s[0] = '\0';
}

void strDestruir(strDinamico &s)
{
    delete[]s;
    s = NULL;
}

void scan(strDinamico &cadena)
{
    strCrear(cadena);

    strDinamico cadenaAux;
    cadenaAux = new char [MAX];

    int i = 0;
    char c;

    fflush(stdin);
    scanf("%c", &c);

    while(i < MAX-1&& c != '\n')
    {
        cadenaAux[i] = c;
        scanf("%c", &c);
        i++;
    }
    cadenaAux[i] = '\0';
    strCop(cadena, cadenaAux);
    strDestruir(cadenaAux);
}

void print (strDinamico s)
{
    int i = 0;
    while(s[i]!= '\0')
    {
        printf ("%c", s[i]);
        i++;
    }
}

int strLar (strDinamico s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void strCop (strDinamico &s1, strDinamico s2)
{
    delete[]s1;
    int largo = strLar(s2);
    s1 = new char[largo+1];
    int i = 0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

boolean strEq (strDinamico s1, strDinamico s2)
{
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;

}


//CONCATENAR SEGUNDO STRING AL FINAL DEL PRIMERO
void strCon(strDinamico &cadenaConcatenada, strDinamico cadena1, strDinamico cadena2)
{
    strCrear(cadenaConcatenada);
    int largoCadena1 = strLar(cadena1);
    int largoCadena2 = strLar(cadena2);
    int nuevoLargo = largoCadena1  + largoCadena2 + 1;

    if(nuevoLargo > MAX)
    {
        nuevoLargo = MAX;
    }

    cadenaConcatenada = new char [nuevoLargo];

    int copyIndex = 0;
    for(int i = copyIndex; i < largoCadena1; i++)
    {
        cadenaConcatenada[i] = cadena1[i];
        copyIndex++;
    }

    int copyIndex2 = 0;
    int i = 0;
    for(i = copyIndex; i < nuevoLargo - 1; i++)
    {
        cadenaConcatenada[i] = cadena2[copyIndex2];
        copyIndex2++;
    }

    cadenaConcatenada[i] = '\0';
}


//PRIMER STRING MENOR AL SEGUNDO
boolean strMen(strDinamico cadena1, strDinamico cadena2)
{
    int i = 0;

    boolean menor = FALSE;
    boolean terminar = FALSE;

    while(cadena1[i] != '\0' && cadena2[i] != '\0' && terminar == FALSE)
    {
        if (toupper(cadena1[i]) == toupper(cadena2[i]))
        {
            i++;
        }
        else
        {
            terminar = TRUE;
            if(toupper(cadena1[i]) < toupper(cadena2[i]))
            {
                menor = TRUE;
            }
        }
    }

    if(cadena1[i] == '\0' && cadena2[i] != '\0')
    {
        menor = TRUE;
    }

    return menor;
}

boolean validarStringAlfabetico(strDinamico s)
{
    boolean esAlfabetico = TRUE;
    int i=0;
    while(s[i]!='\0' && esAlfabetico)
    {
        if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            i++;
        else
            esAlfabetico = FALSE;
    }
    return esAlfabetico;
}

boolean validarStringNumerico(strDinamico s)
{
    boolean esNumerico = TRUE;
    int x=0;
    while(s[x]!='\0' && esNumerico)
    {
        if((s[x] >= 48 && s[x] <= 57) || (x == 0 && s[x] == 45))
            x++;
        else
            esNumerico = FALSE;
    }
    return esNumerico;
}

boolean validarStringNumericoDistintoDeCero(strDinamico s)
{
    boolean distintoDeCero = FALSE;

    int x=0;
    while(s[x]!='\0' && distintoDeCero == FALSE)
    {
        if(s[x] == 48)
            x++;
        else
            distintoDeCero = TRUE;
    }

    return distintoDeCero;
}

//Precondición: s no puede ser vac�o ni tener espacios vac�os al principio y/o al final, debe ser un string num�rico.
int convertirStringAEntero(strDinamico s)
{
    int i = 0, resultado = 0;
    boolean negativo = FALSE;

    while(s[i]!='\0')
    {
        if(s[i] != 45)
        {
            int nro = s[i] - 48;
            resultado =  (resultado * 10) + nro;
        }
        else
        {
            negativo = TRUE;
        }

        i++;
    }

    if(negativo == TRUE)
        return resultado * -1;
    else
        return resultado;
}

//Precondición: s2 es un string alfabetico no vacío.
void eliminarEspaciosVaciosAlInicio(strDinamico &s1, strDinamico s2)
{
    int i = 0, iInsertar = 0; // i UTILIZADO PARA RECORRER s2, iInsertar utilizado para inserción en s1
    boolean espacioEliminado = FALSE;

    while(s2[i] != '\0')
    {
        if(espacioEliminado == TRUE || s2[i] != 32)
        {
            if(espacioEliminado == FALSE)
            {
                s1 = new char[(strLar(s2) - i) + 1];
                espacioEliminado = TRUE;
            }

            s1[iInsertar] = s2[i];
            iInsertar++;
        }

        i++;
    }

    if(espacioEliminado == FALSE)
        s1 = new char[1];

    s1[iInsertar] = '\0';
}

int strLarPrimerPalabra (strDinamico s)
{
    int i = 0;
    while (s[i] != '\0' && s[i] != 32)
        i++;
    return i;
}

//Precondición: s es un string alfabetico no vacío y el primer caracter no es un espácio.
void obtenerPrimerPalabra(strDinamico &s1, strDinamico &s2, strDinamico sEntrada)
{
    int largoPrimerPalabra = strLarPrimerPalabra(sEntrada);// CANTIDAD DE CARACTERES DE LA PRIMER PALABRA DE sEntrada
    s1 = new char[largoPrimerPalabra + 1];// CANTIDAD DE CARACTERES DE LA PRIMER PALABRA DE sEntrada + 1 PARA EL CARACTER NULO
    s2 = new char[(strLar(sEntrada) - largoPrimerPalabra) + 1];// CANTIDAD DE CARACTERES QUE OCUPA EL RESTO DEL STRING + 1 PARA EL CARACTER NULO

    int i = 0, iInsertar = 0; // i UTILIZADO PARA RECORRER sEntrada, iInsertar utilizado para inserción en s1 y s2
    boolean resto = FALSE;

    while(sEntrada[i] != '\0')
    {
        if(resto == FALSE)
        {
            s1[iInsertar] = sEntrada[i];

            // SI EL CARACTER QUE ACABO DE INSERTAR, FUE EL ULTIMO DE LA PRIMER PALABRA, PASO AL RESTO
            if(iInsertar == largoPrimerPalabra - 1)
            {
                s1[iInsertar + 1] = '\0';
                resto = TRUE;
                iInsertar = -1;
            }
        }
        else
        {
            s2[iInsertar] = sEntrada[i];
        }

        i++;
        iInsertar++;
    }

    s2[iInsertar] = '\0';
}

//Precondición: El archivo viene abierto para escritura.
void bajarString(strDinamico s, FILE * f)
{
    int i=0;
    while(s[i]!='\0')
    {
        fwrite(&s[i],sizeof(char),1,f);
        i++;
    }
    fwrite(&s[i],sizeof(char),1,f);
}

//Precondición: El archivo viene abierto para lectura.
void levantarString(strDinamico &s,FILE * f)
{
    int i = 0;
    strDinamico aux = new char[MAX];
    char c;
    fread(&c,sizeof(char),1,f);
    while(c!='\0' && !feof(f))
    {
        aux[i]=c;
        fread(&c,sizeof(char),1,f);
        i++;
    }
    aux[i]='\0';
    strCop(s,aux);
    strDestruir(aux);
}

void convertirNombreArchivo(strDinamico &nombreArchivo, strDinamico id)
{

    strDinamico aux, rutaRelativa = "../", extension = ".dat";

    strCrear(nombreArchivo);

    strCon(aux, id, extension);
    strCon(nombreArchivo, rutaRelativa, aux);
}
