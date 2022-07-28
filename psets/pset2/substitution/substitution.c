#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_alpha(string s);
char substitution(char c, string k);

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

    // Get user input
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Loop the string
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Print the letter substitution
        printf("%c", substitution(plaintext[i], argv[1]));
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

char substitution(char c, string k)
{
    if (isupper(c))
    {
        // 'H' - 65 = 7
        // 72 - 65 = 7
        int posiUpper = c - 65;

        // Return based on position
        return k[posiUpper];
    }

    if (islower(c))
    {
        // 'H' - 97 = 7
        // 104 - 97 = 7
        int posiUpper = c - 97;

        // Return based on position
        return k[posiUpper];
    }

    // If not a letter, return the same char
    return c;
}

// printf("-> %i\n", (('Y' - 65) + 3) % 26);