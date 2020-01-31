/*
The program calculates probability that the manager has no skill, based on his/her performance throughout investment horizon and true forecasts.

Based on sequential binomial distribution. Benchmarking the performance of manager decision-making against hypothesis that manager's DM skill equals to coin toss (1/2)

$ cc manager_performance.c -o manager_performance -lm

*/

#include <stdio.h>
#include <math.h>

unsigned factorial(unsigned a);
double power(double n, unsigned p);

int main(int argc, char const *argv[]) {
    double n; // investment horizon
    double t; // num of true forecasts
    double p = 0.5; // coin toss skill
    double Px = 0; // probability of success w/o skill
    int status;

    // request total periods & true forecasts
    printf("Enter total number of forecasts provided by the investment manager:\n");
    while (((status = scanf("%lf", &n)) != 1) || (n < 1)) {
        if (status != 1)
            scanf("%*s"); // dispose invalid chars
        printf("Enter non-negative integer, e.g. 10\n");
    }
    printf("Enter number of TRUE forecasts:\n");
    while (((status = scanf("%lf", &t)) != 1) || (t < 1) || (t > n)) {
        if (status != 1)
            scanf("%*s"); // dispose invalid chars
        if (t > n) {
            printf("Number of true forecasts must be less than total forecasts.\n");
            continue;
        }
        printf("Enter non-negative integer, e.g. 9\n");
    }

    /* Px += factorial(n)/factorial(i)/factorial(n-i) * p^i * (1-p)^(n-i); */
    for (double i = t; i <= n; i++) {
        Px += factorial(n)/factorial(i)/factorial(n-i) * pow(p, i) * pow((1-p), (n-i));
    }
    printf("The probability of achieving similar investment performance WITHOUT having a skill is %.4lf\n", Px);
    return 0;
}

unsigned factorial(unsigned a) {
    unsigned prod = 1;
    for (int i = 2; i <= a; i++) {
        prod *= i;
    }
    return prod;
}
