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


    printf("%c", rotate('Y', atoi(argv[1])));

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
        // return (char) ((c - 65) + k) % 26;
        return ''
    }

    return 'F';
}

// printf("-> %i\n", (('Y' - 65) + 3) % 26);