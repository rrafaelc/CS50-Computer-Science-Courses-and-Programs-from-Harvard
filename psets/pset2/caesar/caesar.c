#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // If has one command, which is call the file ./caesar
    // And if has more than 2 commands ./caesar 1 2
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }


    printf("%c\n", rotate('Y', atoi(argv[1])));

}

bool only_digits(string s)
{
    // Loop the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Check if all is digit
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

char rotate(char c, int k)
{
    if (isupper(c))
    {
        // (('Y' - 65) + 3) % 26 = 1
        // 65 + 1 = 66
        // 66 ASCII = 'B'
        int shiftUpper = ((c - 65) + k) % 26;

        return (char) 65 + shiftUpper;
    }

    if (isupper(c))
    {
        // (('y' - 97) + 3) % 26 = 1
        // 97 + 1 = 98
        // 98 ASCII = 'b'
        int shiftLower = ((c - 97) + k) % 26;

        return (char) 65 + shiftLower;
    }

    // If not a letter, return the same char
    return 'f';
}

// printf("-> %i\n", (('Y' - 65) + 3) % 26);