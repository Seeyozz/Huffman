#ifndef  h_main
#define  h_main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List
{
    struct List *next;
    int occur;
    char c;
}List;

#include "bit.h"
#include "occurences.h"
#include "tree.h"

char *fileToString(char *filename);
void printList(struct List* list);

#endif 