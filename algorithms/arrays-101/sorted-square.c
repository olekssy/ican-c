/* Given an integer array nums sorted in non-decreasing order,
 * return an array of the squares of each number sorted in non-decreasing order.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3574/
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "arrays.h"

int* sortedSquares(int* nums, int numsSize, int* returnSize);

int main(void) {
    int numsSize = 5;
    int* returnSize = &numsSize;
    int nums[] = {-4, -1, 0, 3, 10};

    show_array(nums, numsSize);
    show_array(sortedSquares(nums, numsSize, returnSize), *returnSize);

    return EXIT_SUCCESS;
}


int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int* squared = (int*)malloc(numsSize * sizeof(int));
    int pointerLeft = 0;
    int pointerRight = numsSize - 1;

    for (int i = pointerRight; i >= 0; i--) {
        if (abs(nums[pointerLeft]) > nums[pointerRight]) {
            squared[i] = nums[pointerLeft] * nums[pointerLeft];
            pointerLeft++;            
        } else {
            squared[i] = nums[pointerRight] * nums[pointerRight];
            pointerRight--;
        }
    }
    return squared;
}
