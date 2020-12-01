#ifndef  h_occurences
#define  h_occurences

#include "main.h"

void writeOccur(char* filename);
void listOccur(struct List* result, char *filename);
List *create_Element(char c, int id, int occur);
List *create_list(int size);
#endif