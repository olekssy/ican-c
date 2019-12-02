#include <stdio.h>
#include "delay.h"

int main(void) {
    const char SIGN = '$';
    int rows = 100;
    int cols;
    for (int row = 0, cols = 1; row < rows; row++, cols++) {
        for (int i = 0; i < cols; i++) {
            delay(10000);
            printf("%c", SIGN);
        }
        printf("\n");
    }
    return 0;
}
