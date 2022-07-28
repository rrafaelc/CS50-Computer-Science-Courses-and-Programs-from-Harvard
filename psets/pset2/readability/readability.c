#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    printf("Letters: %i\n", letters);
}

int count_letters(string text)
{
    int c_letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]))
        {
            c_letters++;
        }
        else if (isupper(text[i]))
        {
            c_letters++;
        }
    }

    return c_letters;
}

int count_words(string text)
{
    return 0;
}

int count_sentences(string text)
{
    return 0;
}