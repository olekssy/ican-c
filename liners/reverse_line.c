#include <stdio.h>
#include <string.h>

int main(void) {
    const int LIMIT = 255;
    char array[LIMIT];
    char ch;
    int last;
    printf("Enter a line: ");
    for (int i = 0, ch = 1; ch != '\n'; i++) {
        scanf("%c", &array[i]);
        ch = array[i];
    }
    //print in reverse
    last = strlen(array);
    for (int i = last; i > -1; i--) {
        printf("%c", array[i]);
    }
    printf("\nDone.\n");
    return 0;
}
