#ifndef  h_main
#define  h_main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bit.h"

typedef struct List
{
    struct List *next;
    int data;
}List;

void writeDico(char* filename);
char *fileToString(char *filename);

#endif 