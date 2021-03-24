/* Given a fixed length array arr of integers,
 * duplicate each occurrence of zero, shifting
 * the remaining elements to the right. 
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3245/
 */

#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"

int main(void) {
    const int arrSize = 7;
    int arr[arrSize] = {
        [0] = 1,
        [2] = 2,
        [4] = 3
    };

    print_array(arr, arrSize);

    for (size_t i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            for (size_t k = arrSize - 1; k > i; k--) {
                arr[k] = arr[k - 1];
            }
            i++;
        }
    }

    print_array(arr, arrSize);

    return EXIT_SUCCESS;
}

