#include "apue.h"

int
main(void)
{
    int c;
    while ((c = getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
           // err_sys("output error");
           fputs("output error\0", stdout);
    
    if (ferror(stdin))
        fputs("input error\0", stdout);
    
    exit(0);
}
