#include "bit.h"

void fromTextToBit(char *s)
{
    int i;
    //char *buffer;

    FILE *fp = fopen("data/output.txt", "w");

    if (!fp)
    {
        printf("Unable to create output file.\n");
        exit(EXIT_FAILURE);
    }

    for(; *s != 0; ++s)
    {
        //printf("%c => ", *s);
        
        for(i = 7; i >= 0; --i) 
            (*s & 1 << i) ? fputc('1', fp) : fputc('0', fp);

        //putchar('\n');
    }

    

    //char buffer[1024];

    // for (int k = 0; k < 256; k++)
    // {
    //     if (count[k] > 0)
    //     {
    //         snprintf(buffer, sizeof(buffer), "%c = %d\n", k, count[k]);
    //     }

    //     fputs(buffer, fp);
    //     memset(buffer, '\0', sizeof(buffer));
    // }

    fclose(fp);
}

