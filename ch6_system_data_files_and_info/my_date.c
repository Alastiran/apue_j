#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    time_t current_time;
//    struct tm *current_time_st;
    char time_string[50];


    if ((current_time = time(NULL)) < 0) {
        printf("problem with getting Time");
        exit(1);
    }

    struct tm *current_time_st = gmtime(&current_time);

    if (strftime(time_string, 
                50,
                "%W %b %d %H:%M:%S %Z %Y",
                current_time_st
                )
        == 0) {
        printf("problem with time formatting");
        exit(1);
    }

    puts(time_string);
}

    





    
    
