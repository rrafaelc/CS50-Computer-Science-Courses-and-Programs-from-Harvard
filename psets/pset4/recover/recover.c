#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check the arguments
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Get the filename
    char *filename = argv[1];


    // Open file as read mode
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Could not open %s\n", filename);
        return 1;
    }

    fclose(f);
}