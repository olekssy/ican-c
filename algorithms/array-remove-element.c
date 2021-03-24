/* 
 * Given an array nums and a value val, 
 * remove all instances of that value 
 * in-place and return the new length.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3247/
 * */

#include <stdlib.h>
#include <stdio.h>

void print_array(int arr[], int arrSize);

int main(void) {
    int numsSize = 4;
    int nums[] = {
        [0] = 2,
        [1] = 3,
        [2] = 3,
        [3] = 2
    };
    int val = 3;
    int p = numsSize - 1;

    print_array(nums, numsSize);
    printf("%d\n", val);

    for (int i = p; i >= 0; i--) {
        if (nums[i] == val) {
            nums[i] = nums[p];
            p--;
            numsSize--;
        }
    }

    print_array(nums, numsSize);

    return EXIT_SUCCESS;
}

void print_array(int arr[], int arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

