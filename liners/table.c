#include <stdio.h>

int main(void) {
    int low, up;
    int n, ns, nc;
    printf("Enter lower and upper limits: ");
    scanf("%i %i", &low, &up);
    printf("\tn \t n^2 \t n^3\n");
    for (n = low; n <= up; n++) {
        ns = n*n;
        nc = ns*n;
        printf("%4i \t%4i \t%4i\n", n, ns, nc);
    }
    return 0;
}
