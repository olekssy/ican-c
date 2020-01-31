#include <stdio.h>

void rlist(int n);

int main(void) {
        int k = 0;
        rlist(k);
        return 0;
}

void rlist(int n) {
        printf("Loc %d is %p\n", n, &n);
        if (n < 4) {
                rlist(n+1);
        }
        printf("LOC %d is %p\n", n, &n);
}
