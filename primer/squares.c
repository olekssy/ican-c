#include <stdio.h>

int main(void) // function calculates squares of the input
{
  int x; // input variable
  int y; // result variable

  printf("Enter number\n");
  scanf("%d", &x);
  y = x * x;
  printf("%d squared equals to %d.\n", x, y);

  return 0;
}
