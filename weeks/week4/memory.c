#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));

    x[0] = 72;
    x[1] = 73;
    x[3] = 33;

    printf("");

    return 0;
}