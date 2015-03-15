#include <stdio.h>
#include <sys/utsname.h>

int 
main(void)
{
    struct utsname *my_sys;

    if (uname(my_sys) < 0)
        printf("Problem reading uname");

    printf("System: %s \n", my_sys->sysname);
    printf("Nodename: %s \n", my_sys->nodename);
    printf("Release: %s \n", my_sys->release);
    printf("Version: %s \n", my_sys->version);
    printf("Machine: %s \n", my_sys->machine);
}


