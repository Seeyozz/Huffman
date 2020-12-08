#include "main.h"

int main(int argc, char *argv[])
{
    //gcc -Wall -Wextra -Werror -std=c99 -O1 -o main *.c

    (void)argc;

    char *filename = argv[1];

    writeOccur(filename);

    fromTextToBit(fileToString(filename));

    List *result = (List *)malloc(sizeof(List));
    listOccur(result, "data/occur.txt");
}

char *fileToString(char *filename) //return a string containing the content of a text file
{
    char *s;
    FILE *f = fopen(filename, "r");

    fseek(f, 0, SEEK_END);
    int length = ftell(f);
    fseek(f, 0, SEEK_SET);
    s = malloc(length);
    if (s)
    {
        fread(s, 1, length, f);
    }
    fclose(f);

    return s;
}

void printList(struct List* list) //Print a linked list
{
    while (list != NULL)
    {
        printf("%c = %d\n", list->c, list->occur);
        list = list->next;
    }
}