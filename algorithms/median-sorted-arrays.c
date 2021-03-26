/* Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(void) {
    int nums1Size = 2;
    int nums2Size = 2;

    int nums1[] = {
       [0] = 1,
       [1] = 3
    };
    int nums2[] = {
       [0] = 2,
       [1] = 4
    };

    print_array(nums1, nums1Size);
    print_array(nums2, nums2Size);

    printf("%2.4f\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

    return EXIT_SUCCESS;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double median;
    const int nums3Size = nums1Size + nums2Size;
    int mp = (int) nums3Size / 2;   // median pointer
    int nums3[nums3Size];

    // merge sorted arrays into nums3
    int p1 = nums1Size - 1;
    int p2 = nums2Size - 1;
    int p3 = nums3Size - 1;

    print_array(nums3, nums3Size);

    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] < nums2[p2]) {
            nums3[p3] = nums2[p2];
            p2--;
        }
        else {
            nums3[p3] = nums1[p1];
            p1--;
        }
        p3--;

        print_array(nums3, nums3Size);
    }

    while (p1 >= 0 || p2 >= 0) {
        if (p1 >= 0) {
            nums3[p3] = nums1[p1];
            p1--;
        }
        else {
            nums3[p3] = nums2[p2];
            p2--;
        }
        p3--;
        print_array(nums3, nums3Size);

    }

    // calculate median
    if (nums3Size % 2) {
        median = (float) nums3[mp];
    }
    else {
        median = ((float) nums3[mp] + (float) nums3[mp - 1]) / 2;

    }

    return median;
}
