#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // If has one command, which is call the file ./caesar
    // And if has more than 2 commands ./caesar 1 2
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }



    // printf("-> %i\n", (('Y' - 65) + 3) % 26);
}

bool only_digits(string s)
{
    // Check if have a letter
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");

            return false;
        }
    }
}