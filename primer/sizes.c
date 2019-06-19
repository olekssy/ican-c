#include <stdio.h>

int main(void) // show type sizes of data structure
{
  printf("Integer uses %zd bytes.\n", sizeof(int));
  printf("Char uses %zd bytes.\n", sizeof(char));
  printf("Long uses %zd bytes.\n", sizeof(long));
  printf("Long long uses %zd bytes.\n", sizeof(long long int));
  printf("Double uses %zd bytes.\n", sizeof(double));
  printf("Double long uses %zd bytes.\n", sizeof(double long));
  return 0;
}
