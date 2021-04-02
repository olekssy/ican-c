/* Return the minimum number of students that must move in order
 * for all students to be standing in non-decreasing order of height.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3228/
 */

#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"

int heightChecker(int* heights, int heightsSize);

int main(void) {
    int arrSize = 5;
    int arr[] = {6, 2, 3, 4, 5};

    show_array(arr, arrSize);
    printf("%d\n", heightChecker(arr, arrSize));


    return EXIT_SUCCESS;
}

int heightChecker(int* heights, int heightsSize) {
    int* arrSorted = malloc(heightsSize * sizeof(int));
    int steps = 0;

    // duplicate and sort initial array
    for (int i = 0; i < heightsSize; i++) {
        *(arrSorted + i) = *(heights + i);
    }
    // Insertion sort of int array
    int pr, pw;
    int key;
    for (int pr = 1; pr < heightsSize; pr++) {
        key = *(arrSorted + pr);
        pw = pr - 1;
        while (pw >= 0 && arrSorted[pw] > key) {
            arrSorted[pw + 1] = *(arrSorted + pw);
            pw--;
        }
        arrSorted[pw + 1] = key;
    }

    // count how many elements are out of place
    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != arrSorted[i]) {
            steps++;
        }
    }
    return steps;
}
