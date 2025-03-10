#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include <stdio.h>

typedef enum {FALSE, TRUE} boolean;

void boolScan(boolean &boolParam);
void boolPrint(boolean boolParam);

#endif // BOOLEAN_H_INCLUDED
