#include <stdio.h>

int main(void) {
    float deposit = 1000000.0;
    float R = 1.08;
    float wdraw = 100000.0;
    int t;
    for (t = 1; deposit > 0; t++) {
        deposit *= R;
        deposit -= wdraw;
    }
    printf("Deposit = $%.1f \nT = %i years\n", deposit, t);
    return 0;
}
