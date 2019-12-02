#include <stdio.h>
#include <stdbool.h>

bool getPrime(int n);

int main(void) {
    int lim, n;
    printf("Enter positive integer: ");
    while (scanf("%i", &lim)) {
        //check if positive
        if (lim <= 0) {
            printf("Limit must be positive. Try again: ");
            continue;
        }
        //check if lim >= 2
        else if (lim >= 2) {
            printf("2 ");
        }
        //iterate through odd ints till lim
        for (n = 3; n <= lim; n+=2) {
            if (getPrime(n)) {
                printf("%i ", n);
            }
        }
        printf("\nEnter positive integer (q to quit): ");
    }
    printf("Done\n");
    return 0;
}

bool getPrime(int n) {
    bool isprime = true;
    int i;
    //iterate till i*i < n
    for (i = 3; i*i <= n; i+=2) {
        if (n%i==0) {
            isprime = false;
            break;
        }
    }
    return isprime;
}
