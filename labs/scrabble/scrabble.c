#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
}

int compute_score(string word)
{
    int score = 0;

    // For loop by the length of word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (islower(word[i]))
        {
            // The alphabet has 26 letters, in lower case, the ASCII z finish in 122
            // Then subtract 122 to current word in ASCII, for example b, that is 98
            // 122 - 98 equals 24, so 26 - 24 equal 2, the second in position in ASCII
            // To be easy to use array points, add 1, because the c language counts from 0
            // So the 24 will be 25. Then 26 - 25 equal 1, the "second" position in the array points
            int posiLower = 26 - ((122 - word[i]) + 1);

            // Add points to score, base on position given from the code above
            score += POINTS[posiLower];
        }
        else if (isupper(word[i]))
        {
            // The same as above, but the uppercase Z letter finish at 90
            int posiUpper = 26 - ((90 - word[i]) + 1);

            score += POINTS[posiUpper];

        }

        // islower or isupper already check if is only letters
        // Numbers and others characters will return false
    }

    printf("Score: %i\n", score);

    return score;
}
