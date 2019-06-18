#include <math.h>
#include <stdio.h>

// include -lm flag to compile pow
// cc  main.c -o main -lm

void schedule(double p, int t, double r, float mp);
int main(void) {
  long double p;  // principal amount
  int t;          // number of years
  long double r;  // interest rate
  long double mp; // monthly pmt

  // prompt user for variables
  printf("Enter principal amount = ");
  scanf("%Lg", &p);
  printf("Enter number of years = ");
  scanf("%d", &t);
  printf("Enter interest rate (e.g. 0.05) = ");
  scanf("%Lg", &r);

  // calculate monthly pmt
  mp = p * r / 12 / (1 - pow(1 + r / 12, -t * 12));
  printf("Monthly payment = %Lg\n", mp);

  // display schedule of payments
  schedule(p, t, r, mp);

  return 0;
}

void schedule(double p, int t, double r,
              float mp) // display schedule of monthly payments
{
  double balance;
  balance = p;

  printf("\n==Schedule of monthly payments==\n");
  printf("Month\t|\tpayment\t|\tbalance\n");

  for (size_t i = 1; i < t * 12 + 1; ++i) {
    balance = balance * (1 + r / 12) - mp;
    printf("%ld\t|\t%lg\t|\t%lg\n", i, mp, balance);
  }
}
