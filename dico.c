#include "dico.h"

int isLeaf(struct Node *tree)
{
    if (!tree->right && !tree->left)
        return 1;
    return 0;
}

void printCode(char *code, char c)
{
    //(void)code;

    char buffer[4096] = {0};

    FILE *f = fopen("data/dico.txt", "a");

    if (!f)
    {
        printf("Unable to create dico file.\n");
        exit(EXIT_FAILURE);
    }

    snprintf(buffer, sizeof(buffer), "%c = %s\n", c, code);
    fputs(buffer, f);

    fclose(f);
}

void getDico(struct Node *tree, char *code)
{
    if (!tree)
        return;

    if (isLeaf(tree))
        return printCode(code, tree->data);

    getDico(tree->left, strcat(code, "0"));
    code[strlen(code) - 1] = '\0';
    getDico(tree->right, strcat(code, "1"));
    code[strlen(code) - 1] = '\0';
    //code[strlen(code) - 1] = '\0';

    //memset(code, '\0', 256);
}