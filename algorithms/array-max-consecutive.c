/* Given a binary array, find the maximum 
 * number of consecutive 1s in this array.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3238/
 */

#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"

int main(void) {
    int numsSize = 6;
    int nums[] = {
        [0] = 1,
        [1] = 1,
        [2] = 0,
        [3] = 1,
        [4] = 1,
        [5] = 1
    };
    unsigned count = 0;
    unsigned countBest = 0;

    print_array(nums, numsSize);

    for (size_t i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count++;

            if (count > countBest) {
                countBest = count;
            }
        }
        else {
            count = 0;
        }
    }

    printf("%u\n", countBest);

    return EXIT_SUCCESS;
}
