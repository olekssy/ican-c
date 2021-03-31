/* Given an integer array nums, move all 0's to the end of it 
 * while maintaining the relative order of the non-zero elements.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3157/
 */

#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"

void moveZeroes(int* nums, int numsSize);

int main(void) {
    size_t numsSize = 5;
    int nums[] = {
        [0] = 0,
        [1] = 1,
        [2] = 0,
        [3] = 3,
        [4] = 12
    };

    print_array(nums, numsSize);

    moveZeroes(nums, numsSize);

    print_array(nums, numsSize);

    return EXIT_SUCCESS;
}

void moveZeroes(int* nums, int numsSize){
    size_t writePointer = 0;
    size_t zeroCount = 0;

    for (size_t readPointer = 0; readPointer < numsSize; readPointer++) {
        if (*(nums + readPointer)) {
            *(nums + writePointer) = *(nums + readPointer);
            writePointer++;
        }
        else {
            zeroCount++;
        }
    }
    for (size_t i = numsSize - zeroCount; i < numsSize; i++) {
        * (nums + i) = 0;
    }
}
