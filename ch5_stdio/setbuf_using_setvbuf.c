#include <stdio.h>

void my_setbuf(FILE *, char *);

int
main(void)
{
    char jbuf[BUFSIZ];
    FILE *jfp;

    //open a stream
    jfp = fopen("readme.me", "r");
    my_setbuf(jfp, &jbuf);

}

void my_setbuf(FILE *stream, char *buf)
{
    //given a stream, call 
    setvbuf( stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ);

}

