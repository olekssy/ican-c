/* Given an array arr of integers, check if there exists two integers N and M 
 * such that N is the double of M ( i.e. N = 2 * M).
 *
 * More formally check if there exists two indices i and j such that :
 *
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arrays.h"

bool checkIfExist(int* arr, int arrSize);

int main(void) {
    int arrSize = 4;
    int arr[] = {
        [0] = 7,
        [1] = 1,
        [2] = 14,
        [3] = 11
    };

    print_array(arr, arrSize);
    printf("%s\n", checkIfExist(arr, arrSize) ? "true" : "false");

    return EXIT_SUCCESS;
}

bool checkIfExist(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            continue;
        }
        for (int j = 0; j < arrSize; j++) {
            if (j == i) {
                continue;
            }
            if (arr[i] == 2 * arr[j]) {
                return true;
            }
        }
    }
    return false;
}

