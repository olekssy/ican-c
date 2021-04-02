/* Return the minimum number of students that must move in order 
 * for all students to be standing in non-decreasing order of height.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3228/
 */

#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"

int heightChecker(int* heights, int heightsSize);
void insertionSort(int* arr, size_t arrSize);

int main(void) {
    int arrSize = 5;
    int arr[] = {6, 2, 3, 4, 5};

    show_array(arr, arrSize);
    insertionSort(arr, arrSize);
    show_array(arr, arrSize);

    return EXIT_SUCCESS;
}

int heightChecker(int* heights, int heightsSize) {
    int steps = 0;

    return steps;
}

void insertionSort(int* arr, size_t arrSize) {
    /* In-place insertion sort of int array */
    size_t pr, pw;
    int key;

    for (size_t pr = 1; pr < arrSize; pr++) {
        key = *(arr + pr);
        pw = pr - 1;
        while (pw >= 0 && arr[pw] > key) {
            arr[pw + 1] = *(arr + pw);
            pw--;
        }
        arr[pw + 1] = key;
    }
}

