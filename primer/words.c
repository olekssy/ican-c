#include <stdio.h>

void one_three(void);
void two(void);

int main(void) // call function one_three
{
  printf("start:\n");
  one_three();
  printf("finish!\n");

  return 0;
}

void one_three(void) // calls function two
{
  printf("one\n");
  two();
  printf("three\n");
}

void two(void) // print statement
{
  printf("two\n");
}
