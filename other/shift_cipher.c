#include <ctype.h>
#include <stdio.h>
/*
Julius Ceasar cipher
*/
#define SHIFT -1
int main(void) {
  char ch;
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch))
      putchar(ch + SHIFT);
    else
      putchar(ch);
  }
  putchar(ch);
  return 0;
}
