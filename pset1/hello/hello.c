#include <stdio.h>
#include <cs50.h>

int main(void)
{
  printf("Hello, world!\n");

  string nome = get_string("Qual é seu nome? \n");

  printf("Olá, %s \n", nome);
}