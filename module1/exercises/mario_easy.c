#include <stdio.h>
#include <cs50.h>

int get_user_height(void);
void pyramid(int height);

int main(void)
{
  int height = get_user_height();

  pyramid(height);
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

void pyramid(int height)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = i; j > 1; j--)
    {
      printf("#");
    }
    printf("\n");
  }
  // printf("\n");
}
