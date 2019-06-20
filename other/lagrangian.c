#include <math.h>
#include <stdio.h>

/*
Approximation algorithm for locating Lagrangian points L1, L2, L3
ref.: https://www-istp.gsfc.nasa.gov/stargaze/Slagrang.htm
*/

int main(void) {
  double m1, m2;   // masses of the large and small object, respectively
  double mr;       // mass ratio
  double r;        // distance between the two main objects
  double L1 = 0.0; // distance of the L1 point from the smaller object
  double L1_ref;   // reference value
  double L1_best;
  double abs_error = 1e+30;
  double abs_error_t; // converges to zero as solution to optimization problem

  m1 = 5.9722e+24; // Earth mass in kg
  m2 = 7.342e+22;  // Moon mass in kg
  r = 384402e+3;   // distance from Earth to Moon in meters
  L1_ref = 3.2639e+8;

  // Optimize for L1
  for (double i = 1; i < r * 2; i += 1) {
    L1 += i;
    abs_error_t = m1 / (r - L1 + i) / (r - L1 + i) - m2 / (L1 + i) / (L1 + i) -
                  m1 / r / r + (L1 + i) * (m1 + m2) / r / r / r;
    if (fabs(abs_error) > fabs(abs_error_t)) {
      abs_error = abs_error_t;
      L1_best = L1;
      printf("L1 = %.10g| abs_error = %g\n", L1, abs_error_t);
    }
  }
  printf("\nComputed L1 = %g\n", L1_best);
  printf("abs_error = %.6g\n", abs_error);

  return 0;
}
