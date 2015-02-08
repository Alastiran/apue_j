#include "apue.h"
#include <unistd.h>

int
main(void)
{
    pid_t child_id = fork();
    if (child_id == 0)
        printf("hello world from child, process ID %d\n", getpid());
    else
        printf("hello world from parent, process ID %d\n", getpid());

    exit(0);
}
