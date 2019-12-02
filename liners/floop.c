#include <stdio.h>

int main(void) {
    const char SIGN = 'F';
    int cols, rows = 6;
    for (int row = 0, cols = 1; row < rows; row++, cols++) {
        for (int i = 0; i < cols; i++) {
            printf("%c", SIGN - i);
        }
        printf("\n");
    }
    return 0;
}
