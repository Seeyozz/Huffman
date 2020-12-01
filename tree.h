#ifndef  h_tree
#define  h_tree

#include "main.h"

typedef Node* Tree;

void print_tree(Tree tree);
Node* create_node_tree(char val, int occur);
void freeTree(struct Node *tree);
void mergeTheTwoSmallest(struct List_Node **huffList);
List_Node* huffman(struct List_Node* list);
List_Node *huffList(struct List *list, int id);
void printHuffmanList(struct List_Node *huffList);
List_Node *createNodeList(struct Node *tree, int id);
void push(struct List_Node** head_ref, Node *new_data, int id);

#endif