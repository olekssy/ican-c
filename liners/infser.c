#include <stdio.h>

double sum1(unsigned limit);
double sum2(unsigned limit);

int main(void) {
    unsigned limit;
    printf("Enter limit: ");
    while (scanf("%i", &limit) == 1) {
        printf("S1 = %lf\n", sum1(limit));
        printf("S2 = %lf\n", sum2(limit));
        printf("Enter limit: ");
    }
    printf("Done.\n");
    return 0;
}

double sum1(unsigned limit) {
    double sum = 0;
    for (unsigned i = 1; i <= limit; i++) {
        sum += 1.0/i;
    }
    return sum;
}
double sum2(unsigned limit) {
    double s = 0;
    for (unsigned i = 1; i <= limit; i += 2) {
        s += 1.0/i;
    }
    for (unsigned i = 2; i <= limit; i += 2) {
        s -= 1.0/i;
    }
    return s;
}
