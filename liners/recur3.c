/* convert integer into binary via recursion */
#include <stdio.h>

void rbin(int k);

int main(void) {
    unsigned n;
    printf("Enter non-negative integer: ");
    while(scanf("%u", &n) == 1) {
        printf("\nBinary of %u is ", n);
        rbin(n);
        printf("\nEnter non-negative integer: ");
    }
    printf("Done.\n");
    return 0;
}

void rbin(int k) {
    int r;
    r = k % 2;
    if (k >= 2) {
        rbin(k/2);
    }
    putchar(r == 0 ? '0' : '1');
}
