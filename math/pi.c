#include <stdio.h>

// calculate pi to a selected precision
// with the Nilakantha series

int main(void) {
  unsigned n; // num of iterations
  unsigned precision;
  long double c = 1.0; // control var
  long double pi = 3.0;

  printf("Enter floating-point precision AND number of iteration: ");
  scanf("%u %u", &precision, &n);

  for (size_t i = 2; i <= n * 2; i += 2) {
    pi += c * 4 / (i * (i + 1) * (i + 2));
    c = -c;
  }
  printf("pi = %1.*Lg\n", precision + 1, pi);

  return 0;
}
