/* Universal helper function definitions for operations on arrays. */

#include <stdlib.h>
#include <stdio.h>

void show_array(const int* arr, size_t arrSize) {
    /* Display elements of int array */
    for (size_t i = 0; i < arrSize; i++) {
        printf("%d ", * (arr + i));
    }
    printf("\n");
}

int* duplicateArray(int* arr, size_t arrSize) {
    /* Duplicate int array, return copy array pointer */
    int* arrCopy = (int*)malloc(arrSize * sizeof(int));
    for (size_t i = 0; i < arrSize; i++) {
        *(arrCopy + i) = *(arr + i);
    }
    return arrCopy;
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
