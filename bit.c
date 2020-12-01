#include "bit.h"

void fromTextToBit(char *s) //convert a text to binary and put it in the file output.txt
{
    int i;

    FILE *fp = fopen("data/output.txt", "w");

    if (!fp)
    {
        printf("Unable to create output file.\n");
        exit(EXIT_FAILURE);
    }


    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    for (int j = 0; j < len; j++)
    {
        char ch = s[j];
        for (i = 7; i >= 0; --i)
            (ch & 1 << i) ? fputc('1', fp) : fputc('0', fp);
    }

    fclose(fp);
}