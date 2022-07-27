#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Name: ");

    int i = 0;

    while (name[i] != '\0')
    {
        printf("%c", name[i]);
        i++;
    }

    printf("%i\n", i);
}