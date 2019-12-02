#include <stdio.h>
#define NUM 2
#define LIM 16

unsigned power(int b, int p);

int main(void) {
    unsigned pows[LIM];
    for (int i = 0; i < LIM; i++) {
        pows[i] = power(NUM, i);
    }
    // print array
    for (int k = 0; k < LIM; k++) {
        printf("%u ", pows[k]);
    }
    printf("\nDone.\n");
    return 0;
}

unsigned power(int b, int p) {
    unsigned res = b;
    for (int n = 0; n < p; n++) {
        res *= b;
    }
    return res;
}
