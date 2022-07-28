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
}

int count_letters(string text)
{}

int count_words(string text)
{}

int count_sentences(string text)
{}