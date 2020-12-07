#include "occurences.h"

void writeOccur(char *filename) //put the character and his number of occurences in the file occur.txt
{
    int count[256] = {0};
    FILE *f = fopen(filename, "r");

    if (!f)
    {
        printf("Unable to read file.\n");
        exit(EXIT_FAILURE);
    }

    int c = 0;
    while ((c = fgetc(f)))
    {
        if (c == EOF)
            break;

        //printf("char = %d\n", c);

        count[c] += 1;
    }

    fclose(f);

    FILE *fp = fopen("data/occur.txt", "w");

    if (!fp)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[4096] = {0};

    int first = 1;

    for (int k = 0; k < 256; k++)
    {
        if (first)
        {
            if (count[k] > 0)
            {
                snprintf(buffer, sizeof(buffer), "%c = %d", k, count[k]);
                first = 0;
                //printf("char = %c\n", k);
            }
        }

        else
        {
            if (count[k] > 0)
            {
                snprintf(buffer, sizeof(buffer), "\n%c = %d", k, count[k]);
                //printf("char = %c\n", k);
            }
        }

        int fput = fputs(buffer, fp);
        if (fput == EOF)
        {
            return;
        }

        memset(buffer, '\0', sizeof(buffer));
    }

    fclose(fp);
}

void listOccur(struct List *result, char *filename) //fill the linked list result with the char and the number of occur
{
    assert(result != NULL);

    char *line = NULL;
    size_t len = 0;
    int read = 0;

    FILE *f = fopen(filename, "r");

    if (!f)
    {
        printf("Unable to read file.\n");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    int id = 1;
    //char occur[1024];
    char * temp;
    int co = 4;

    int first_jump = 0;

    while ((read = getline(&line, &len, f)) != -1)
    {
        if (line[0] == '\n')
        {
            first_jump = 1;
            continue;
        }
        co = 4;
        
        if (first_jump)
        {
            result->c = '\n';
            first_jump = 0;
            co = 3;
        }
        else
        {
            result->c = line[0];
        }
        
        result->id = id;
        result->occur = strtol(line + co, &temp, 10);
            // if(*temp != '\0')
            //     printf("Could not convert\n");

        
        // else
        // {
        //     result->occur = strtol(line + co, &temp, 10);
        //     if(*temp != '\0')
        //         printf("Could not convert\n");
        // }

        // if (line[strlen(line) - 1] == '\n')
        // {
        //     line[strlen(line) - 1] = '\0';
        // }

        
        
        //result->tree = NULL;

        if (result->next)
        {
            result = result->next;
        }
        id++;
    }

    //free(occur);

    fclose(f);
}

List *create_Element(char c, int id, int occur)
{
    struct List *new_el;
    new_el = (List *)malloc(sizeof(List));
    new_el->c = c;
    new_el->id = id;
    new_el->occur = occur;
    //new_el->tree = NULL;
    new_el->next = NULL;
    return new_el;
}

List *create_list(int size)
{
    if (size <= 0)
    {
        return NULL;
    }
    else
    {
        List *myel = create_Element('\0', 0, 0);
        myel->next = create_list(size - 1);
        return myel;
    }
}
