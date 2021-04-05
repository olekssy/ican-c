/* Given integer array nums, return the third maximum number in this array.
 * If the third maximum does not exist, return the maximum number.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3231/
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "arrays.h"

int thirdMax(int* nums, int numsSize);

int main(void) {
    int numsSize = 4;
    int nums[] = {2, INT_MIN, 2, 1, 3};

    show_array(nums, numsSize);
    printf("%d\n", thirdMax(nums, numsSize));

    return EXIT_SUCCESS;
}

int thirdMax(int* nums, int numsSize) {
    long int a = LONG_MIN;
    long int b = LONG_MIN;
    long int c = LONG_MIN;
    int uniqueCount = numsSize;
    bool threeUnique = true;

    for (size_t i = 0; i < numsSize; i++) {
        if (nums[i] == a || nums[i] == b || nums[i] == c) {
            uniqueCount--;
            continue;
        } else if (nums[i] > a) {
            c = b;
            b = a;
            a = nums[i];
        } else if (nums[i] > b) {
            c = b;
            b = nums[i];
        } else if (nums[i] > c) {
            c = nums[i];
        }
    }

    if (uniqueCount < 3) {
        threeUnique = false;
    }

    return threeUnique ? c : a;
}
