#include <stdio.h>

int main(void) {
  // initialize variable
  int dogs;

  printf("How many dogs you have?\n");
  // request variable from input
  scanf("%d", &dogs);
  // return message with variable
  printf("So, you have %d dog(s)!\n", dogs);

  return 0;
}
