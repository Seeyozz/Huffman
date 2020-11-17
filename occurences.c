#include "occurences.h"

void writeOccur(char *filename) //put the char and his number of occurences in the file occur.txt
{
    int count[256] = {0};
    FILE *f = fopen(filename, "r");

    if (!f)
    {
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(f)))
    {
        if (c == EOF)
            break;

        count[c] += 1;
    }

    fclose(f);

    FILE *fp = fopen("data/occur.txt", "w");

    if (!fp)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];

    int first = 1;

    for (int k = 0; k < 256; k++)
    {
        if (first)
        {
            if (count[k] > 0)
            {
                snprintf(buffer, sizeof(buffer), "%c = %d", k, count[k]);
                first = 0;
            }
        }

        else
        {

            if (count[k] > 0)
            {
                snprintf(buffer, sizeof(buffer), "\n%c = %d", k, count[k]);
            }
        }

        fputs(buffer, fp);
        memset(buffer, '\0', sizeof(buffer));
    }

    fclose(fp);
}

void listOccur(struct List *result, char *filename) //fill the linked list result with the char and the number of occurences
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *f = fopen(filename, "r");

    if (!f)
    {
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, f)) != -1)
    {
        result->c = line[0];
        result->occur = atoi(&line[read - 2]);
        result->next = malloc(sizeof(List));
        result = result->next;
    }
}