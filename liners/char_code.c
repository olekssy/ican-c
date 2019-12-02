#include <stdio.h>
#define CHAR_PER_LINE 8
#define STOP '#'

int main(void) {
	char ch;
	int count = 0;
	while ((ch = getchar()) != STOP) {
		printf("%2c %3i | ", ch, ch);
        count++;
        if (count%CHAR_PER_LINE == 0)
            printf("\n");
	}
    printf("\nDone.\n");
    return 0;
}
