#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool only_alpha(string s);
bool has_duplicate_characters(string s);
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

    // If not have only alphabet
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

    // If have duplicate characters
    if (has_duplicate_characters(argv[1]))
    {
        printf("Duplicate characters not allowed.\n");

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

bool has_duplicate_characters(string s)
{
    // ASCII for upper letter
    for (int i = 65; i < 90; i++)
    {
        // Check letter by letter, return true if find duplicated
        int count = 0;
        for (int j = 0, n = strlen(s); j < n; j++ )
        {
            // 'A' == 'A'
            // 'A' == 65
            if (toupper(s[j]) == i)
            {
                count++;
            }

            // If count is higher than 1, return true
            if (count > 1)
            {
                return true;
            }
        }
    }

    return false;
}

char substitution(char c, string k)
{
    if (isupper(c))
    {
        // 'H' - 65 = 7
        // 72 - 65 = 7
        int posiUpper = c - 65;

        // Return based on position and make sure is upper
        return (char) toupper(k[posiUpper]);
    }

    if (islower(c))
    {
        // 'H' - 97 = 7
        // 104 - 97 = 7
        int posiLower = c - 97;

        // Return based on position and make sure is lower
        return (char) tolower(k[posiLower]);
    }

    // If not a letter, return the same char
    return c;
}
