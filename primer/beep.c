#include <stdio.h>

int main(void) // show code of the character
{
  char beep;

  printf("Enter character: ");
  scanf("%c", &beep);

  printf("The code for %c is %d\a\n", beep, beep);

  return 0;
}
