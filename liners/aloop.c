#include <stdio.h>

int main(void) {
    char letter = 'A';
    int cols, rows = 6;
    int offset;
    for (int row = 0, cols = 1; row < rows; row++, cols++, letter += offset) {
        for (offset = 0; offset < cols; offset++) {
            printf("%c", letter + offset);
        }
        printf("\n");
    }
    return 0;
}
