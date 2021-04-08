/* Given an integer n, return true if it is a power of four. Otherwise, return false.
https://leetcode.com/problems/power-of-four/ */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "helpers.h"

bool isPowerOfFour(int n);

int main(void) {
    int n = 1;

    printf("%s\n", isPowerOfFour(n) ? "true" : "false");

    return EXIT_SUCCESS;
}

bool isPowerOfFour(int n) {
    while (n % 4 == 0 && n > 0) {
        n /= 4;
    }
    return n == 1 ? true : false;
}