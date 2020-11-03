#include "main.h"

int main(int argc, char *argv[])
{
    //gcc -Wall -Wextra -Werror -std=c99 -O1 -o main *.c

    (void)argc;

    char* filename = argv[1];

    writeDico(filename);
}

void writeDico(char* filename)
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

    FILE *fp = fopen("data/dico.txt", "w");

    if (!fp)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];

    for (int k = 0; k < 256; k++)
    {
        if (count[k] > 0)
        {
            snprintf(buffer, sizeof(buffer), "%c = %d\n", k, count[k]);
        }

        fputs(buffer, fp);
        memset(buffer, '\0', sizeof(buffer));
    }

    fclose(fp);
}