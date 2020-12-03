#include "encode.h"

char *getCode(char c, const char *dico)
{
    FILE *f = fopen(dico, "r");

    if (!f)
    {
        printf("can't read file.\n");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    int read = 0;

    char *code = (char *)malloc(sizeof(char));

    while ((read = getline(&line, &len, f)) != -1)
    {
        if (line[0] == c)
        {
            code = line + 4;
            //printf("check code = %s\n", code);
            break;
        }
    }

    fclose(f);

    return code;
}

void writeCode(char *code)
{
    FILE *f = fopen("data/output.txt", "a");

    if (!f)
    {
        printf("Unable to create output file.\n");
        exit(EXIT_FAILURE);
    }

    //fprintf(f, "%s", code);
    fputs(code, f);

    fclose(f);
}

void encode(const char *input)
{
    remove("data/output.txt");
    
    FILE *f = fopen(input, "r");

    if (!f)
    {
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
    }

    char c = 0;
    while ((c = fgetc(f)))
    {
        if (c == EOF)
            break;
        writeCode(getCode(c, "data/dico.txt"));
    }

    fclose(f);
}