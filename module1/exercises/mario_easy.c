#include <stdio.h>
#include <cs50.h>

int get_user_height(void);

int main(void)
{
  int height = get_user_height();
}

int get_user_height(void)
{
  int n;

  do
  {
    n = get_int("Height: ");
  } while (n < 1 || n > 8);
  return n;
}
