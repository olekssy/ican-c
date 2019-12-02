#include <stdio.h>

void cubed(double n);

int main(void) {
    double n;
    printf("Enter number: ");
    scanf("%lf", &n);
    cubed(n);
    return 0;
}

void cubed(double n) {
    printf("Num cubed = %.2lf\n", n*n*n);
}
