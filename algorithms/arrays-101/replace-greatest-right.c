/* Given an array arr, replace every element in that array 
 * with the greatest element among the elements to its right, 
 * and replace the last element with -1.
 * After doing so, return the array.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arrays.h"

int* replaceElements(int* arr, int arrSize, int* returnSize);

int main(void) {
    int arrSize = 6;
    int arr[] = {
        [0] = 17,
        [1] = 18,
        [2] = 5,
        [3] = 4,
        [4] = 6,
        [5] = 1
    };

    print_array(arr, arrSize);
    print_array(replaceElements(arr, arrSize, &arrSize), arrSize);

    return EXIT_SUCCESS;
}

int* replaceElements(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;

    for (size_t i = 0; i < arrSize; i++) {
        // replace last element with -1
        if (i == arrSize - 1) {
            arr[i] = -1;
            break;
        }
        int maxVal = 0;
        // find k-th largest element to the right
        for (size_t k = i + 1; k < arrSize; k++) {
            if (arr[k] > maxVal) {
                maxVal = arr[k];
            }
        }
        // replace i-th element with k-th
        arr[i] = maxVal;
    }

    return arr;
}
