#include <stdio.h>

#define PINT 2
#define OUNCE 8
#define TABLE 2
#define TEA 3

int main(void) {
    float cups;
    printf("Enter number of cups: ");
    scanf("%f", &cups);

    printf("%.2f pints\n", cups/PINT);
    printf("%.2f ounces\n", cups*OUNCE);
    printf("%.2f tablespoons\n", cups*OUNCE*TABLE);
    printf("%.2f teaspoons\n", cups*OUNCE*TABLE*TEA);
    return 0;
}
