/* Universal helper functions for
 * operations on arrays.
 */

#include <stdlib.h>
#include <stdio.h>

void print_array(int* arr, int arrSize);

void print_array(int* arr, int arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        printf("%d ", * (arr + i));
    }
    printf("\n");
}
