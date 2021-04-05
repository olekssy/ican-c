/* Given an array nums of n integers where nums[i] is in the range [1, n],
 * return an array of all the integers in the range [1, n] that do not appear in nums.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3270/
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "arrays.h"

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize);

int main(void) {
    int numsSize = 8;
    int* returnSize = &numsSize;
    int nums[] = {4,3,2,7,8,2,3,1};

    show_array(nums, numsSize);
    show_array(findDisappearedNumbers(nums, numsSize, returnSize), *returnSize);

    return EXIT_SUCCESS;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *missing = calloc(numsSize + 1, sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; ++i)
        missing[nums[i]] = 1;

    for (int i = 1; i <= numsSize; ++i)
        if (missing[i] == 0)
            missing[(*returnSize) ++] = i;

    return missing;
}
