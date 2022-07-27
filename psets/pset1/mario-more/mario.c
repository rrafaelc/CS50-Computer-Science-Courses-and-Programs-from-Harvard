#include <stdio.h>
#include <cs50.h>

int get_user_height(void);
void pyramid(int height);

int main(void)
{
    // Get user height input
    int height = get_user_height();

    pyramid(height);
}

int get_user_height(void)
{
    int n;

    // Prompt input for user height until get in range of 1 - 8
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    return n;
}

void pyramid(int height)
{
    // Loop for the amount of height
    for (int i = 0; i < height; i++)
    {
        // Get the amount of hash needed
        int hash = i + 1;

        // The spaces is the height - hash
        int spaces = height - hash;

        // Do a loop for spaces first
        for (int s = 0; s < spaces; s++)
        {
            printf(" ");
        }

        // Do a loop for hash
        for (int h = 0; h < hash; h++)
        {
            printf("#");
        }

        // Print the 2 spaces for gap in current line
        for (int g = 0; g < 2; g++)
        {
            printf(" ");
        }

        // Print the hash again for the next pyramid
        for (int h = 0; h < hash; h++)
        {
            printf("#");
        }

        printf("\n");
    }

}
