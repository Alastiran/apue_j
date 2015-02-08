#include "apue.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFSIZE 64

int main(void)
{
    int n;
    char buf[BUFFSIZE];
    char additional[BUFFSIZE];

    struct stat st;
    stat("in_text_to_change.txt", &st);

    int mydes = open("in_text_to_change.txt", O_RDWR | O_APPEND);

    off_t fsize = st.st_size;
    off_t new_off = lseek(mydes, fsize / 2, SEEK_SET);

    n = read(mydes, buf, BUFFSIZE);
    printf("%s", buf);

    //now write
    strcpy(additional, "here is the next text, i just inserted now\n\0");
    //write(mydes, additional, BUFFSIZE);
    pwrite(mydes, additional, BUFFSIZE, fsize / 2);

}
