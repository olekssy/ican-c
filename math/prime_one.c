/* random primes generator */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned get_prime(unsigned prime_cap);
unsigned get_q(unsigned prime_cap, unsigned p);

unsigned prime, p, q;
unsigned prime_cap = 30;
bool is_prime;

int main(void) {
    p = get_prime(prime_cap);
    printf("p = %u\n", p);


    return 0;
}

unsigned get_q(unsigned prime_cap, unsigned p) {
    return q;
}

unsigned get_prime(unsigned prime_cap) {
    prime = 1;
    while (prime < 4) {
        srand(time(NULL));               // seed initialization, should only be called once.
        prime = rand() % prime_cap;      // pseudo-random integer between 0 and RAND_MAX
    }
    while (true) {
        is_prime = true;
        if (prime % 2 == 0) {
            prime += 1;
        }
        for (unsigned i = 3; i*i <= prime; i += 2) {
            if (prime % i == 0) {
                is_prime = false;
                prime += 2;
                break;
            }
        }
        if (is_prime) {
            break;
        }
    }
    return prime;
}
