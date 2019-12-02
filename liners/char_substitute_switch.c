#include <stdio.h>
#define PERIOD '.'
#define EXCL '!'
#define END '#'

int main(void) {
    char ch;
    int count = 0;

    while ((ch = getchar()) != END) {
        switch (ch) {
            case PERIOD:
                putchar(EXCL);
                count++;
                break;
            case EXCL:
                putchar(EXCL);
                putchar(EXCL);
                count++;
                break;
            default:
                putchar(ch);
        }
    }
    printf("Substitution count: %i\n", count);
    return 0;
}
