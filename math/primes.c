#include <math.h>
#include <stdio.h>

// Discover prime numbers within range

int main(void) {
  unsigned start, stop;
  unsigned n_sqrt, rem;

  printf("Enter lower and upper limits of range: ");
  scanf("%u %u", &start, &stop);
  printf("Prime numbers:\n");

  // check if start num is even
  if (start % 2 == 0) {
    start += 1;
  }
  // increment step 2 to skip even nums
  for (unsigned n = start; n < stop; n += 2) {
    rem = 1;
    n_sqrt = (unsigned)sqrt(n);
    // try divisors in range [3, sqrt(n)]
    for (unsigned i = 3; i <= n_sqrt; ++i) {
      if (n % i == 0) {
        rem = 0;
        break;
      }
    }
    if (rem != 0) {
      printf("%u\n", n);
    }
  }

  return 0;
}
