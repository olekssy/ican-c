/* Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
https://leetcode.com/problems/two-sum/ */

#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(void) {
    int numsSize = 4;
    int nums[] = {2,7,11,15};
    int target = 9;
    int returnSize;

    show_array(nums, numsSize);
    show_array(twoSum(nums, numsSize, target, &returnSize), returnSize);

    return EXIT_SUCCESS;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int* addends = malloc(*returnSize * sizeof(int));

    for (size_t i = 0; i < numsSize - 1; i++) {
        for (size_t k = i + 1; k < numsSize; k++) {
            if (nums[i] + nums[k] == target) {
                *(addends) = i;
                *(addends + 1) = k;
                return addends;
            }
        }
    }

    return addends;
}
