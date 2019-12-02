#include <stdio.h>

#define CM_IN 2.54

int main(void) {
    unsigned h;
    printf("Enter your height in cm: ");
    scanf("%u", &h);

    printf("Your height in inches: %.2f\n", h/CM_IN);
    return 0;
}
