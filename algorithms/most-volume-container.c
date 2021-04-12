/* Given n non-negative integers a1, a2, ..., an , where each represents 
a point at coordinate (i, ai). n vertical lines are drawn such that 
the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, 
which, together with the x-axis forms a container, 
such that the container contains the most water.

 https://leetcode.com/problems/container-with-most-water/ */

 #include <stdlib.h>
 #include <stdio.h>
 #include "helpers.h"

int maxArea(int* height, int heightSize);

int main(void) {
    int heightSize = 9;
    int height[] = {1,8,6,2,5,4,8,3,7};

    show_array(height, heightSize);
    printf("%d\n", maxArea(height, heightSize));

    return EXIT_SUCCESS;
}

int maxArea(int* height, int heightSize) {
    int maxSurface = 0;
    int surface;
    size_t pLeft = 0;
    size_t pRight = heightSize - 1;

    while (pLeft != pRight) {
        surface =  (pRight - pLeft) * (*(height + pLeft) > *(height + pRight) ? height[pRight] : height[pLeft]); 
        maxSurface = (surface > maxSurface ? surface : maxSurface);

        if (*(height + pLeft) > *(height + pRight)) {
            pRight--;
        } else {
            pLeft++;
        }
    }

    return maxSurface;
}
