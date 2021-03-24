/* Given a fixed length array arr of integers,
 * duplicate each occurrence of zero, shifting
 * the remaining elements to the right. 
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3245/
 * */

#include <stdlib.h>
#include <stdio.h>

void print_array(unsigned arr[], size_t arr_size);

int main(void) {
    const size_t SIZE = 7;
    unsigned arr[SIZE] = {
        [0] = 1,
        [2] = 2,
        [4] = 3
    };

    print_array(arr, SIZE);

    for (size_t i = 0; i < SIZE; i++) {
        if (arr[i] == 0) {
            for (size_t k = SIZE - 1; k > i; k--) {
                arr[k] = arr[k - 1];
            }
            i++;
        }
    }

    print_array(arr, SIZE);

    return EXIT_SUCCESS;
}

void print_array(unsigned arr[], size_t arr_size) {
    for (size_t i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    };
     printf("\n");
}
