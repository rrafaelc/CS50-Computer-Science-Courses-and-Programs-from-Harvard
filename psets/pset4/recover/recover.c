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
}