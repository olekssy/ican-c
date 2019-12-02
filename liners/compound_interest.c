#include <stdio.h>

int main(void) {
    float s0 = 100.0;
    float inv_a, inv_b;
    float rs = .1;
    float Rc = 1.05;
    int t = 1;
    // estimate for t=1
    inv_a = s0*(1 + rs);
    inv_b = s0*Rc;
    //compute T
    for (t = 2; inv_a > inv_b; t++) {
        inv_a = s0*(1 + rs*t);
        inv_b *= Rc;
    }
    printf("T = %i years \ninv_A = $%.1f \ninv_B = $%.1f\n", t, inv_a, inv_b);
    return 0;
}
