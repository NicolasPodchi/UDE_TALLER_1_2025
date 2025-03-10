#include "boolean.h"

void boolScan(boolean &boolParam)
{
    int num;
    scanf("%d", &num);

    if (num == 1)
    {
        boolParam = TRUE;
    }
    else
    {
        boolParam = FALSE;
    }
}

void boolPrint(boolean boolParam)
{
    switch(boolParam)
    {
    case TRUE:
        printf("Verdadero");
        break;

    case FALSE:
        printf("Falso");
        break;
    }
}













