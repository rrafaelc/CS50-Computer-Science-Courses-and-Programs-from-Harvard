#include <stdio.h>

int main(void)
{
    // int n = 50;
    // int *p = &n;
    // printf("%p\n", p);
    // printf("%i\n", *p);

    char *s = "HI!";
    char *p = &s[0];
    printf("%p\n", p);
    printf("%p\n", s);
}