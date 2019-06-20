#include <stdio.h>

// Fibonacci series calculator

int main(void) {
  unsigned long num_prev = 1;
  unsigned long num = 2;
  unsigned long num_next;
  unsigned count;

  printf("Enter how many numbers to compute: ");
  scanf("%u", &count);

  printf("1\t| %lu\n", num_prev);
  printf("2\t| %lu\n", num);
  for (unsigned i = 3; i <= count; i++) {
    num_next = num_prev + num;
    num_prev = num;
    num = num_next;
    printf("%u\t| %lu\n", i, num);
  }

  return 0;
}
