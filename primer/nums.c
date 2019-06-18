#include <stdio.h>

int main(void) // dec to oct and hex converter
{
  int num;

  printf("Enter number in DEC: ");
  scanf("%d", &num);

  printf("Number in OCT = %#o\n", num);
  printf("Number in HEX = %#x\n", num);

  return 0;
}
