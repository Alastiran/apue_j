#include <stdio.h>

int
main(void)
{
    int output;
    char jbuf[BUFSIZ];

    output = printf("");

    sprintf(jbuf, "output is:%d", output);

    fputs(jbuf,stdout);
}
