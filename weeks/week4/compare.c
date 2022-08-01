#include <cs50.h>
#include <stdio.h>


int main(void)
{
    char s = get_string("s: ");
    char t = get_string("t: ");

    if (strcmp(s, t))
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}