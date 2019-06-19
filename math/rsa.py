import numpy as np

# simple RSA encryption generator


def gcd(a, b):
    if b > a:
        return gcd(b, a)
    if a % b == 0:
        return b
    return gcd(b, a % b)


def get_prime(lower, upper):
    def is_prime(n):
        ri_sqrt = int(np.sqrt(randint))
        for n in range(2, ri_sqrt + 1):
            if randint % n == 0:
                return False
        return True
    while True:
        randint = np.random.randint(low=lower,
                                    high=upper
                                    )
        if is_prime(randint):
            return randint


def get_e(phi, precision):
    res = 2
    while gcd(res, phi) != 1:
        res += 1
        if res > precision:
            res = 1
            break
    return res


def get_d(e, phi, precision):
    res = 2
    while res * e % phi != 1:
        res += 1
        if res > precision:
            res = 1
            break
    return res


def encrypt(txt, e, n):
    return txt**e % n


def decrypt(cyph, d, n):
    return cyph**d % n


def main():
    p_limit = 5012
    precision = p_limit * 10_000
    # initialize random primes
    p = q = 1
    while p == q:
        p = get_prime(1024, p_limit)
        q = get_prime(1024, p_limit)
    n = p * q
    # get totient
    phi = (p - 1) * (q - 1)
    # get e, d
    e, d = 2, 2
    while e == d:
        e = get_e(phi, precision)
        d = get_d(e, phi, precision)

    print(f'p = {hex(p)} \nq = {hex(q)}\n'
          f'n = {hex(n)} \nphi = {hex(phi)}\n')
    print(f'Public key:  n = {hex(n)} e = {hex(e)}\n'
          f'Private key: n = {hex(n)} d = {hex(d)}\n')
    # test encryption/decription and
    mes = int(input('Enter int to encrypt: '))
    mes_encr = encrypt(mes, e, n)
    mes_decr = decrypt(mes_encr, d, n)
    print(f'Encrypted val: {hex(mes_encr)}\n'
          f'Decrypted val: {mes_decr}\n'
          f'Vals match = {mes==mes_decr}\n')

    return 0


if __name__ == '__main__':
    main()
