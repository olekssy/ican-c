/* Given an array A of non-negative integers, 
 * return an array consisting of all the even elements of A, 
 * followed by all the odd elements of A.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3260/
 */

#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"

int* sortArrayByParity(int* A, int ASize, int* returnSize);

int main(void) {
    int arrSize = 4;
    int* returnSize = &arrSize;
    int arr[] = {
        [0] = 3,
        [1] = 1,
        [2] = 2,
        [3] = 4
    };

    print_array(arr, arrSize);
    print_array(sortArrayByParity(arr, arrSize, returnSize), arrSize);

    return EXIT_SUCCESS;
}

int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    int* arrSorted = malloc(ASize* sizeof(int));
    size_t evenIndex = 0;
    size_t oddIndex = ASize - 1;

    for (size_t i = 0; i < ASize; i++) {
        if (*(A + i) % 2) {
            *(arrSorted + oddIndex) = *(A + i);
            oddIndex--;
        }
        else {
            *(arrSorted + evenIndex) = *(A + i);
            evenIndex++;
        }
    }
    return arrSorted;
}
