#include <stdio.h>

#define MILE 1.609
#define GALLON 3.785

int main(void) {
    float distance, consumed, mpg;
    printf("Enter miles traveled and gallons of gasoline consumed: ");
    scanf("%f %f", &distance, &consumed);
    mpg = distance/consumed;
    printf("%.1f miles per gallon\n", mpg);
    printf("%.1f liters per 100km\n", 1/mpg*GALLON/MILE);
    return 0;
}
