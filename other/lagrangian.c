#include <math.h>
#include <stdio.h>
/*
Approximation algorithm for locating Lagrangian points L1, L2, L3
ref.: https://www-istp.gsfc.nasa.gov/stargaze/Slagrang.htm
*/
#define M_SUN 1.98847e+30
#define M_EARTH 5.9722e+24
#define M_MOON 7.342e+22
#define M_MARS 6.4171e+23
#define M_JUP 1.8982e+27
#define R_EARTH 1.49598023e+11
#define R_MOON 3.84399e+8
#define R_MARS 2.279392e+11
#define R_JUP 7.7857e+11
double comp_L1(double m1, double m2, double r, double acc);
double approx_L1(double m1, double m2, double r);
double approx_L2(double m1, double m2, double r);
double approx_L3(double m1, double m2, double r);
int main(void) {
  double L1_earth, L1_moon, L1_mars, L1_jup;
  double L2_earth, L2_moon, L2_mars, L2_jup;
  double L3_earth, L3_moon, L3_mars, L3_jup;
  // double acc = 1.0e-9;
  // Approximation of L1
  L1_earth = approx_L1(M_EARTH, M_SUN, R_EARTH);
  L1_moon = approx_L1(M_MOON, M_EARTH, R_MOON);
  L1_mars = approx_L1(M_MARS, M_SUN, R_MARS);
  L1_jup = approx_L1(M_JUP, M_SUN, R_JUP);
  // Approximation of L2
  L2_earth = approx_L2(M_EARTH, M_SUN, R_EARTH);
  L2_moon = approx_L2(M_MOON, M_EARTH, R_MOON);
  L2_mars = approx_L2(M_MARS, M_SUN, R_MARS);
  L2_jup = approx_L2(M_JUP, M_SUN, R_JUP);
  // Approximation of L3
  L3_earth = approx_L3(M_EARTH, M_SUN, R_EARTH);
  L3_moon = approx_L3(M_MOON, M_EARTH, R_MOON);
  L3_mars = approx_L3(M_MARS, M_SUN, R_MARS);
  L3_jup = approx_L3(M_JUP, M_SUN, R_JUP);
  // Display results
  printf("Approximation     L1    |    L2    |    L3    \n");
  printf("Sun-Earth     %.4e|%.4e|%.4e\n", L1_earth, L2_earth, L3_earth);
  printf("Earth-Moon    %.4e|%.4e|%.4e\n", L1_moon, L2_moon, L3_moon);
  printf("Sun-Mars      %.4e|%.4e|%.4e\n", L1_mars, L2_mars, L3_mars);
  printf("Sun-Jupiter   %.4e|%.4e|%.4e\n", L1_jup, L2_jup, L3_jup);
  return 0;
}
double approx_L1(double m1, double m2, double r) {
  double y, p;
  y = (m1 < m2) ? (m1 / (m1 + m2)) : (m2 / (m1 + m2));
  p = r * (1 - pow(y / 3, 0.3333333));
  return p;
}
double approx_L2(double m1, double m2, double r) {
  double y, p;
  y = (m1 < m2) ? (m1 / (m1 + m2)) : (m2 / (m1 + m2));
  p = r * (1 + pow(y / 3, 0.3333333));
  return p;
}
double approx_L3(double m1, double m2, double r) {
  double y, p;
  y = (m1 < m2) ? (m1 / m2) : (m2 / m1);
  p = -r * (1 - 5 / 12 * y);
  return p;
}
double comp_L1(double m1, double m2, double r, double acc) {
  double y, z, error, p;
  y = (m1 < m2) ? (m1 / m2) : (m2 / m1);
  for (z = 0.0; z < r; z += acc / 10) {
    error = 1 / (1 - z) / (1 - z) / (1 - z) - y / z / z * (1 - z) - 1;
    if (error > -acc && error < acc)
      break;
  }
  p = r / z;
  return p;
}
