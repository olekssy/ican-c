#include <gmp.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned __int128 uint128;
// simple RSA encryption generator

unsigned gcd(unsigned a, unsigned b);
unsigned get_e(unsigned phi, unsigned acc);
unsigned get_d(unsigned e, unsigned phi, unsigned acc);
unsigned encrypt(unsigned message, unsigned e, unsigned n);
unsigned decrypt(unsigned cypher, unsigned d, unsigned n);

int main(void) {
  unsigned p, q, n, phi;
  unsigned e = 2;
  unsigned d = 2;
  unsigned acc = 2048;
  // unsigned mess, cyph;

  // initialize random primes
  p = 17;
  q = 19;
  n = p * q;
  // get totient
  phi = (p - 1) * (q - 1);
  // get e, d
  while (e == d) {
    e = get_e(phi, acc);
    d = get_d(e, phi, acc);
  }

  printf("Public key: \nn = %u \ne = %u \n", n, e);
  printf("Private key: \nn = %u \nd = %u \n", n, d);

  // printf("Enter message: ");
  // scanf("%u", &mess);
  // // encrypt message
  // // mess = 14;
  // cyph = encrypt(mess, e, n);
  // printf("\nEncrypted message: %u\n", cyph);
  // // decrypt message
  // mess = decrypt(cyph, d, n);
  // printf("Decrypted message: %u\n", mess);

  return 0;
}

// Euclidean algorithm
unsigned gcd(unsigned a, unsigned b) {
  unsigned temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
// get e > 1 coprime to phi: GCD(e, phi) = 1
unsigned get_e(unsigned phi, unsigned acc) {
  unsigned res = 2;
  while (gcd(res, phi) != 1) {
    res += 1;
    if (res > acc) {
      res = 1;
      break;
    }
  }

  return res;
}
// get d: d * e = 1 mod phi
unsigned get_d(unsigned e, unsigned phi, unsigned acc) {
  unsigned res = 2;
  while ((res * e) % phi != 1) {
    res += 1;
    if (res > acc) {
      res = 1;
      break;
    }
  }
  return res;
}
// modular exponentiation algorithm for encrypting
unsigned encrypt(unsigned mess, unsigned e, unsigned n) {
  uint128 result = mess;
  for (int _i = 1; _i < e; ++_i) {
    result = result * mess;
  }
  result = result % n;
  return result;
}
// decrypt with binary exponentiation algorithm
unsigned decrypt(unsigned cypher, unsigned d, unsigned n) {
  const uint128 X_2 = cypher * cypher;
  uint128 result = X_2;
  if (d == 1) {
    result = cypher;
  } else {
    if (d % 2 == 1) {
      d = (unsigned)((d - 1) / 2);
      for (int _i = 0; _i < d; ++_i) {
        result = result * X_2;
      }
      result = result * (unsigned)cypher; // ERROR IN THIS LINE
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
