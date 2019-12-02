#include <stdio.h>

int main(void) {
    char first[10];
    char last[10];
    printf("Enter your name: ");
    scanf("%s %s", first, last);
    printf("Hi, %s %s!\n", last, first);
    return 0;
}
