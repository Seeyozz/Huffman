#include "bit.h"

void fromTextToBit(char *s) //convert a text to binary and put in in the file output.txt
{
    int i;

    FILE *fp = fopen("data/output.txt", "w");

    if (!fp)
    {
        printf("Unable to create output file.\n");
        exit(EXIT_FAILURE);
    }

    for(; *s != 0; ++s)
    {   
        for(i = 7; i >= 0; --i) 
            (*s & 1 << i) ? fputc('1', fp) : fputc('0', fp);

    }

    fclose(fp);
}

