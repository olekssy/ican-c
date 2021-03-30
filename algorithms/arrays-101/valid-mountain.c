/* Given an array of integers arr, return true
 * if and only if it is a valid mountain array.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3251/
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "arrays.h"

bool validMountainArray(int* arr, int arrSize);

int main(void) {
    int arrSize = 4;
    int arr[] = {
        [0] = 4,
        [1] = 3,
        [2] = 2,
        [3] = 1
    };

    print_array(arr, arrSize);
    printf("%s\n", validMountainArray(arr, arrSize) ? "true" : "false");
    return EXIT_SUCCESS;
}

bool validMountainArray(int* arr, int arrSize) {
    bool mountain = false;
    int p;

    if (arrSize >= 3) {
        for (int i = 0; i < arrSize - 1; i++) {
            if (arr[i + 1] > arr[i]) {
                mountain = true;
            }
            else {
                p = i;
                break;
            }
        }
        if (mountain == true) {
            for (int j = p; j < arrSize - 1; j++) {
                if (arr[j + 1] < arr[j]) {
                    continue;
                }
                else {
                    mountain = false;
                    break;
                }
            }
        }
        else {
            mountain = false;
        }
    }
    return mountain;
}
