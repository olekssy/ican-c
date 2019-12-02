#include <stdio.h>

float sqdiff(float x, float y);

int main(void) {
    float a, b;
    printf("Enter two numbers: ");
    while (scanf("%f %f", &a, &b) == 2) {
        printf("Square diff = %.2f\n", sqdiff(a,b));
        printf("Enter two numbers: ");
    }
    printf("Done.\n");
    return 0;
}

float sqdiff(float x, float y) {
    return (x-y)/(x*y);
}
