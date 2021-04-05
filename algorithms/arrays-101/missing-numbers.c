/* Given an array nums of n integers where nums[i] is in the range [1, n],
 * return an array of all the integers in the range [1, n] that do not appear in nums.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3270/
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "arrays.h"

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize);

int main(void) {
    int arrSize = 8;
    int* returnSize = &arrSize;
    int arr[] = {4,3,2,7,8,2,3,1};

    show_array(arr, arrSize);
    show_array(findDisappearedNumbers(arr, arrSize, returnSize), *returnSize);

    return EXIT_SUCCESS;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int maxNumber = INT_MIN;

    // find max element in array
    for (size_t i = 0; i < numsSize; i++) {
        if (nums[i] >= maxNumber) {
            maxNumber = *(nums + i);
        }
    }

    printf("maxNumber = %d\n", maxNumber);

    return nums;
}
