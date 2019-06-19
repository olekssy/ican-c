#include <stdio.h>

// geom progression of grain count on the chess board

int main(void) {
  const unsigned short SQUARES = 64;
  float grain = 1E+0;
  unsigned count = 1;

  printf("Square | Grain count\n");
  printf("%6u | %2.4E\n", count, grain);
  while (count++ < SQUARES) {
    grain = grain * 2;
    printf("%6u | %2.3E\n", count, grain);
  }
  return 0;
}
