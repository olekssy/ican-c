#include <stdio.h>

#define FOOT 30.48
#define INCH 2.54

int main(void) {
    float h_cm, h_in;
    int h_foot;
    h_cm = 1.0;
    while (h_cm > 0) {
        printf("Enter height in cm: ");
        scanf("%f", &h_cm);
        h_foot = h_cm / FOOT;
        h_in = (h_cm - h_foot*FOOT)/INCH;
        printf("%.2f cm = %i feet, %.2f inches\n", h_cm, h_foot, h_in);
    }
    return 0;
}
