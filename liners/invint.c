#include <stdio.h>

int main(void) {
    const int INDEX = 8;
    int list[INDEX];
    printf("Enter 8 ints: ");
    for (int i = 0; i < INDEX; i++) {
        scanf("%i", &list[i]);
    }
    for (int n = INDEX - 1; n > -1; n--) {
        printf("%i ", list[n]);
    }
    printf("\nDone.\n");
    return 0;
}
