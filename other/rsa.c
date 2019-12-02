#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// simple RSA encryption generator

unsigned gcd(unsigned a, unsigned b);
unsigned get_prime(unsigned prime_cap);
unsigned get_p(unsigned prime_cap);
unsigned get_q(unsigned prime_cap);
unsigned get_e(unsigned phi, unsigned cap);
unsigned get_d(unsigned e, unsigned phi, unsigned cap);
unsigned encrypt(unsigned message_init, unsigned e, unsigned n);
unsigned decrypt(unsigned message_enc, unsigned d, unsigned n);

// vars
unsigned prime;
unsigned prime_cap;
bool is_prime;
unsigned p;
unsigned q;
unsigned n;
unsigned phi;
unsigned e;
unsigned d;
unsigned dp;
unsigned dq;
unsigned m1;
unsigned m2;
unsigned cap = 1024;
unsigned message_init;
unsigned message_enc;
unsigned message_dec;

int main(void) {
  // initialize random primes
  p = 11;
  q = 13;
  n = p * q;
  // get totient
  phi = (p - 1) * (q - 1);
  // get e, d
  while (e == d) {
    e = get_e(phi, cap);
    d = get_d(e, phi, cap);
  }

  printf("Public key: \nn = %u \ne = %u \n", n, e);
  printf("Private key: \nn = %u \nd = %u \n", n, d);

  // encrypt message_init
  printf("Enter message: ");
  scanf("%u", &message_init);
  message_enc = encrypt(message_init, e, n);
  printf("Encrypted message: %u\n", message_enc);

  // decrypt to initial message
  message_dec = decrypt(message_enc, d, n);
  printf("Decrypted message: %u\n", message_dec);

  return 0;
}

/*
===== Utilities =====
*/
// Euclidean algorithm
unsigned gcd(unsigned a, unsigned b) {
  unsigned c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
// random primes generator
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

/*
===== Parameter getter =====
*/
// get e > 1 coprime to phi: GCD(e, phi) = 1
unsigned get_e(unsigned phi, unsigned cap) {
  e = 2;
  while (gcd(e, phi) != 1) {
    e += 1;
    if (e > cap) {
      e = 1;
      break;
    }
  }

  return e;
}
// get d: d * e = 1 mod phi
unsigned get_d(unsigned e, unsigned phi, unsigned cap) {
  unsigned res = 2;
  while ((res * e) % phi != 1) {
    res += 1;
    if (res > cap) {
      res = 1;
      break;
    }
  }
  return res;
}

/*
===== Encryption-Decription =====
*/
// modular exponentiation algorithm for encrypting
unsigned encrypt(unsigned message_init, unsigned e, unsigned n) {
  unsigned result = message_init;
  for (int _i = 1; _i < e; ++_i) {
    result = result * message_init;
  }
  result = result % n;
  return result;
}
// decrypt with binary exponentiation algorithm
unsigned decrypt(unsigned message_enc, unsigned d, unsigned n) {
  const unsigned X_2 = message_enc * message_enc;
  unsigned result = X_2;
  if (d == 1) {
    result = message_enc;
  } else {
    if (d % 2 == 1) {
      d = (unsigned)((d - 1) / 2);
      printf("d/2 = %u\n", d);
      for (int _i = 0; _i < d; ++_i) {
        result = result * X_2;
      }
      result = result * message_enc; // ERROR IN THIS LINE
      result = result % n;
    } else {
      if (d % 2 == 0) {
        d = (unsigned)(d / 2);
        for (unsigned _i = 0; _i < d; ++_i) {
          result = result * X_2;
        }
        result = result % n;
      }
    }
  }
  return result;
}
