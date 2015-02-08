#include "apue.h"

int main(int argc, char *argv[]) {
    int i;
    struct stat buf;
    char *ptr;

    for (i = 1; i < argc; i++) {
        if (stat(argv[i], &buf) < 0) {
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode) ) 
            ptr = "regular";
        else if (S_ISDIR(buf.st_mode) ) 
            ptr = "directory";

        printf("%s\n", ptr);
    }

    exit(0);
}
