#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_alpha(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // If has one command, which is call the file ./substitution
    // And if has more than 2 commands ./substitution 1 2
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    if (!only_alpha(argv[1]))
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    // If not have 26 letters
    if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)
    {
        printf("Key must contain 26 characters.\n");

        return 1;
    }

    return 0;

    // Get user input
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Loop the string
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Print the letter shifted
        printf("%c", rotate(plaintext[i], atoi(argv[1])));
    }

    printf("\n");

    return 0;
}

bool only_alpha(string s)
{
    // Loop the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Check if all is alphabet
        if (!isalpha(s[i]))
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
        int shiftUpper = ((c - 65) + k) % 26;

        // 65 + 1 = 66
        // 66 ASCII = 'B'
        return (char) 65 + shiftUpper;
    }

    if (islower(c))
    {
        // (('y' - 97) + 3) % 26 = 1
        int shiftLower = ((c - 97) + k) % 26;

        // 97 + 1 = 98
        // 98 ASCII = 'b'
        return (char) 97 + shiftLower;
    }

    // If not a letter, return the same char
    return c;
}

// printf("-> %i\n", (('Y' - 65) + 3) % 26);