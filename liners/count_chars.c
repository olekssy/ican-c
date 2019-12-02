#include <stdio.h>
#define STOP '#'
#define NLINE '\n'
#define SPACE ' '

int main(void) {
    char ch;
    int spaces=0;
    int nlines=0;
    int total=0;

    while((ch = getchar()) != STOP) {
        total++;
        if (ch == SPACE)
            spaces++;
        if (ch == NLINE)
            nlines++;
    }
    printf("Spaces: %i \nN-lines: %i \nOthers: %i\n", spaces, nlines, total-spaces-nlines);
    return 0;
}
