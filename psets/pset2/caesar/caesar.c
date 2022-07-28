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
    // isalpha(argv[1]);

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        printf("%i\n", isalpha(argv[1][i]));
    }


    // printf("-> %i\n", (('Y' - 65) + 3) % 26);
}