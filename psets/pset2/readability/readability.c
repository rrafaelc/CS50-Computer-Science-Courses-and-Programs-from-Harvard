#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    // Store variables for later
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // For now
    printf("%i Letters\n", letters);
    printf("%i Words\n", words);
    printf("%i Sentences\n", sentences);

    // Calculate using formula
    float l = (float) letters / words * 100;
    float s = (float) sentences / words * 100;
    printf("L is %f\n",  l);
    printf("S is %f\n",  s);

}

int count_letters(string text)
{
    int c_letters = 0;

    // Loop the string text array
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if is lower
        if (islower(text[i]))
        {
            c_letters++;
        }
        // Check if is upper
        else if (isupper(text[i]))
        {
            c_letters++;
        }
    }

    return c_letters;
}

int count_words(string text)
{
    int c_words = 0;

    // Loop the array text
    for (int i = 0, n = strlen(text); i < n; i ++)
    {
        // Count how much spaces in ASCII, which is 32
        if (text[i] == 32)
        {
            c_words++;
        }
    }

    // Add one more to count the final word
    c_words++;

    return c_words;
}

int count_sentences(string text)
{
    int c_sentences = 0;

    // Loop the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if has . ASCII which is 46
        if (text[i] == 46)
        {
            c_sentences++;
        }
        // Check if has ! ASCII which is 33
        else if (text[i] == 33)
        {
            c_sentences++;
        }
        // Check if has ? ASCII which is 63
        else if (text[i] == 63)
        {
            c_sentences++;
        }
    }

    return c_sentences;
}