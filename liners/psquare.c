#include <stdio.h>

int main(void) {
    int low, up, sum;
    printf("Enter lower and upper integer limits: ");
    while (scanf("%i %i", &low, &up) == 2 && low < up) {
        sum = 0;
        for (int n = low; n <= up; n++) {
            printf("%i\n", n*n);
            sum += n*n;
        }
        printf("The sums of the squares from %i to %i is %i\n", low*low, up*up, sum);
    }
    printf("Done.\n");
    return 0;
}
