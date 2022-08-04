#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check the arguments
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char *path = malloc(strlen(argv[1]) * sizeof(char));
    path = argv[1];
    printf("%s\n", path);

    free(path);
}