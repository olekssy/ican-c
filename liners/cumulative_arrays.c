#include <stdio.h>

int main(void) {
    const int L = 3;
    double ar[L], ars[L];
    int i;
    printf("Enter %i floats: ", L);
    for (i = 0; i < L; i++) {
        scanf("%lf", &ar[i]);
    }
    ars[0] = ar[0]; //first entry
    // cumulative sum to ars
    for (i = 1; i < L; i++) {
        ars[i] = ars[i-1] + ar[i];
    }
    // display arrays
    printf(" A1 \tA2\n");
    for (int i = 0; i < L; i++) {
        printf("%5.2lf %5.2lf\n", ar[i], ars[i]);
    }
    printf("\nDone.\n");
    return 0;
}
