#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    fot (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n)
        printf("#");
    }

    printf("\n");
}