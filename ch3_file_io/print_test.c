#include <stdio.h>
#include <string.h>

int main(void)
{
    char tape[20]; // = {'B', 'y', 'e', '\n', '\0'};

    strcpy(tape, "party time \n");

    printf("%s", tape);
}
