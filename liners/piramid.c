#include <stdio.h>

int main(void) {
    const char START = 'A';
    char stop;
    int rows, spaces;
    int r, i, n, d;
    printf("Enter letter [A-Z]: ");
    scanf("%c", &stop);
    rows = stop - START + 1;
    spaces = rows - 1;
    for (r = 0; r < rows; r++, spaces--) {
        //space
        for (i = spaces; i; i--) {
            printf(" ");
        }
        //ascend
        for (n = 0; n < r + 1; n++) {
            printf("%c", START + n);
        }
        //descend
        for (d = 0; d < r; d++) {
            printf("%c", START + n - 2 - d);
        }
        printf("\n");
    }
    return 0;
}
