#include <math.h>
#include <stdio.h>

// Simple mortgage calculator with payments scheduler
// include -lm flag to compile

void schedule(double p, int t, double r, float mp);
int main(void) {
  double p;   // principal amount
  unsigned t; // number of years
  double r;   // interest rate
  double mp;  // monthly pmt

  // prompt user for variables
  printf("Enter principal amount = ");
  scanf("%lg", &p);
  printf("Enter number of years = ");
  scanf("%u", &t);
  printf("Enter interest rate (e.g. 0.05) = ");
  scanf("%lg", &r);

  // calculate monthly pmt
  mp = p * r / 12 / (1 - pow(1 + r / 12, -t * 12));
  printf("Monthly payment = %g\n", mp);

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
