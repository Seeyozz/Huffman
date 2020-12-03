#include "main.h"

int main(int argc, char *argv[])
{
    //gcc -Wall -Wextra -Werror -std=c99 -fsanitize=address -g -O1 -o main *.c

    (void)argc;

    char *filename = argv[1];

    writeOccur(filename);

    char *st;
    st = fileToString(filename);
    fromTextToBit(st);
    free(st);

    FILE *f = fopen("data/occur.txt", "r");
    int counter = 0;
    for (char c = getc(f); c != EOF; c = getc(f))
    {
        if (c == '\n')
            counter++;
    }
    counter++;
    fclose(f);

    List *result = create_list(counter);
    listOccur(result, "data/occur.txt");

    
    List_Node *huffmanList = huffList(result, 1);
    printf("\n");

    huffman(huffmanList);

    // char *code = getCode('c', "data/dico.txt");
    // printf("code for c = %s\n", code);
    // writeCode(code);

    encode(filename);
}

char *fileToString(const char *filename)
{
    char *s;
    int length;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        return NULL; // tu ne peux plus rien faire tout va crash
    }

    if (fseek(f, 0, SEEK_END) < 0 || (length = ftell(f)) < 0 || fseek(f, 0, SEEK_SET) < 0)
    {
        fclose(f);
        return NULL; // tu ne peux plus rien faire tout va crash
    }
    s = malloc((length + 1) * sizeof(*s));
    if (s == NULL)
    {
        fclose(f);
        return NULL; // tu ne peux plus rien faire tout va crash
    }
    s[length] = '\0';
    if ((unsigned long)length != fread(s, 1, length, f))
    {
        free(s);
        fclose(f);
        return NULL; // tu ne peux plus rien faire tout va crash
    }
    fclose(f);

    return s;
}

void printList(struct List *list) //Print a linked list
{
    while (list != NULL)
    {
        // if (list->tree)
        // {
        //     printf("tree ");
        // }

        if (list)
        {
            printf("%c = %d,\n", list->c, list->occur);
        }

        if (!list->next)
        {
            break;
        }

        list = list->next;
    }
}

void deleteNode(struct List_Node **ref, int key)
{
    if (!*ref)
    {
        return;
    }

    struct List_Node *temp = *ref;
    struct List_Node *prev = NULL;

    if (temp != NULL && temp->id == key)
    {
        *ref = temp->next;
        free(temp);
        temp = NULL;
        return;
    }
    //Find the key to be deleted
    while (temp != NULL && temp->id != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL)
        return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
    temp = NULL;
}