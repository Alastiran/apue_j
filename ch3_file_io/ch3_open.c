#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>

int main(void)
{
    int fd = open("new_output_file", O_RDWR | O_CREAT | O_TRUNC, S_IWUSR, S_IWGRP, S_IROTH);

    printf("what is fd? %d \n", fd);
//    fprintf(stderr, "what is size max? " #SIZE_MAX " \n");
}
