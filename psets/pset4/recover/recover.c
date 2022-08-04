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

    unsigned char buffer[3];

    size_t ret = fread(buffer, 3, 3, f);

    if (ret != sizeof(*buffer)) {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }

    printf("ELF magic: %#04x%02x%02x%02x\n", buffer[0], buffer[1],
           buffer[2]);


    fclose(f);
}