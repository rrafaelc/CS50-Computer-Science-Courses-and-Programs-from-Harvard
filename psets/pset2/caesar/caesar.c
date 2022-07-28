#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // If has one command, which is call the file ./caesar
    // And if has more than 2 commands ./caesar 1 2
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }
    // Check if is letter
    int t = atoi(argv[1]);
    isalpha(argv[1]);

    // printf("-> %i\n", (('Y' - 65) + 3) % 26);
}