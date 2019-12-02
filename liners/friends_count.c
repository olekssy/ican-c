#include <stdio.h>

int main(void) {
    const int MAX_FRDS = 150;
    int frds = 5;
    int week;
    for (week = 1; frds < MAX_FRDS; week++) {
        printf("W%i \t%i\n", week-1, frds);
        frds = (frds-week)*2;
    }
    return 0;
}
