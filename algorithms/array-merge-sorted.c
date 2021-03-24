/* Given two sorted integer arrays nums1 and nums2, 
 * merge nums2 into nums1 as one sorted array.
 *
 * https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/
 * */

#include <stdlib.h>
#include <stdio.h>

void print_array(unsigned arr[], int arr_size);

int main(void) {
    const int m = 3;
    const int n = 3;
    const int l = m + n;
    unsigned nums1[l] = {
       [0] = 1,
       [1] = 2,
       [2] = 3
    };
    unsigned nums2[n] = {
       [0] = 2,
       [1] = 5,
       [2] = 6
    };

    int i = m - 1;
    int j = n - 1;
    int k = l - 1;

    print_array(nums1, l);
    print_array(nums2, n);

    while (i >= 0 && j >= 0) {
        if (nums1[i] < nums2[j]) {
            nums1[k] = nums2[j];
            k = k - 1;
            j = j - 1;
        }
        else {
            nums1[k] = nums1[i];
            k = k - 1;
            i = i - 1;
        }
        // print_array(nums1, l);
        // printf("[i, j, k] = [%d, %d, %d]\n", i, j, k);
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        k = k - 1;
        j = j - 1;
        // print_array(nums1, l);
    }
    
    print_array(nums1, l);

    return EXIT_SUCCESS;
}

void print_array(unsigned arr[], int arr_size) {
    for (size_t i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
