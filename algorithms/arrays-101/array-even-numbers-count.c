/* Find Numbers with Even Number of Digits
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3237/
 */

#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"

int main(void) {
    const int numsSize = 4;
    int nums[numsSize] = {
        [0] = 555,
        [1] = 901,
        [2] = 482,
        [3] = 1771
    };
    int count = 0;

    print_array(nums, numsSize);

    for (size_t i = 0; i < numsSize; i++) {
        if (nums[i] >= 1e1 && nums[i] < 1e2) {
            count++;
        }
        else if (nums[i] >= 1e3 && nums[i] < 1e4) {
            count++;
        }
        else if (nums[i] >= 1e5 && nums[i] < 1e6) {
            count++;
        }
    }

    printf("%d\n", count);

    return EXIT_SUCCESS;
}
