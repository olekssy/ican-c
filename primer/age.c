#include <stdio.h>

// convert age from years to seconds

int main(void) {
  unsigned short age_y;
  const float YSEC = 3.156e7;
  float age_sec;

  printf("Enter your age in years: ");
  scanf("%hu", &age_y);

  age_sec = age_y * YSEC;
  printf("Your age in seconds = %g\n", age_sec);

  return 0;
}
