#include <stdio.h>
#define PERIOD '.'
#define EXCL '!'
#define END '#'

int main(void) {
    char ch;
    int count = 0;

    while ((ch = getchar()) != END) {
        if (ch == PERIOD) {
            count++;
            putchar(EXCL);
        }
        else if (ch == EXCL) {
            count++;
            putchar(EXCL);
            putchar(EXCL);
        }
        else
            putchar(ch);
    }
    printf("Substitution count: %i\n", count);
    return 0;
}
