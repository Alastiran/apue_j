#include "apue.h"

#define JMAX 4

int
main(void)
{
    char readhere[JMAX]; //use maxline = 4

    while (fgets(readhere, JMAX, stdin) != NULL)
        if (fputs(readhere, stdout) == EOF)
            fputs("output error\0", stdout);

    if (ferror(stdin))
        fputs("input error\0", stdout);
    
    exit(0);
}

