#include <stdio.h>

// calculate PV of perpetuity

float dt(void);
int main(void) {
  long double cf; // cash-flow of perpetuity
  long double result;

  printf("Enter cash-flow: ");
  scanf("%Lg", &cf);

  result = cf * dt();

  printf("PV of perpeturity = %Lg\n", result);

  return 0;
}

float dt(void) // get discount factor
{
  float rate;
  float d_factor;

  printf("Enter discount rate: ");
  scanf("%f", &rate);
  d_factor = 1 / rate;

  return d_factor;
}
