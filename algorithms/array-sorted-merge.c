/* Given two sorted integer arrays nums1 and nums2, 
 * merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 
are m and n respectively. You may assume that nums1 
has a size equal to m + n such that it has enough space 
to hold additional elements from nums2. */

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
