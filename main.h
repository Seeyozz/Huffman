#ifndef h_main
#define h_main
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node
{
    int occur;
    char data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct List
{
    struct List *next;
    int occur;
    char c;
    struct Node *tree;
    int id;
} List;

typedef struct List_Node
{
    struct Node* data;
    struct List_Node *next;
    int id;
}List_Node;

#include "bit.h"
#include "occurences.h"
#include "tree.h"
#include "encode.h"
#include "dico.h"

char *fileToString(const char *filename);
void printList(struct List *list);
void deleteNode(struct List_Node **head_ref, int key);

#endif