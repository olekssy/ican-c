#include <stdio.h>

int main(void) {
    const int INDEX = 26;
    char alpha[INDEX];
    for (int i = 0; i < INDEX; i++) {
        alpha[i] = 'a' + i;
    }
    for (int n = 0; n < INDEX; n++) {
        printf("%c ", alpha[n]);
    }
    printf("\nDone.\n");
    return 0;
}
