/* 
 * Given a sorted array nums, remove the duplicates 
 * in-place such that each element appears only once 
 * and returns the new length.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3248/
 * */

#include <stdlib.h>
#include <stdio.h>

void print_array(int arr[], int arrSize);

int main(void) {
    int numsSize = 3;
    int nums[] = {
        [0] = 1,
        [1] = 1,
        [2] = 2,
    };
    int p = numsSize - 1;

    print_array(nums, numsSize);

    return EXIT_SUCCESS;
}

void print_array(int arr[], int arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

