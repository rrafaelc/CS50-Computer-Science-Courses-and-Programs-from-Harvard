#include <stdio.h>

int main(void)
{
    // int n = 50;
    // int *p = &n;
    // printf("%p\n", p);
    // printf("%i\n", *p);
    // printf("%p\n", p);
    // printf("%p\n", s);
    // char *p = &s[0];
    // printf("%p\n", &s[0]);
    // char *s = "HI!";

    // char *s = "HI!";
    // printf("%c\n", *s);
    // printf("%c\n", *(s + 1));
    // printf("%c\n", *(s + 2));

    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    printf("%i\n", *numbers);
    printf("%i\n", *(numbers + 1));
    printf("%i\n", *(numbers + 2));
    printf("%i\n", *(numbers + 3));
    printf("%i\n", *(numbers + 4));
    printf("%i\n", *(numbers + 5));
    printf("%i\n", *(numbers + 6));
}