/* Universal helper function definitions for operations on arrays. */

#include <stdlib.h>
#include <stdio.h>

void print_array(const int* arr, int arrSize) {
    /* DEPRECATED */
    for (size_t i = 0; i < arrSize; i++) {
        printf("%d ", * (arr + i));
    }
    printf("\n");
}

void show_array(const int* arr, size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        printf("%d ", * (arr + i));
    }
    printf("\n");
}

