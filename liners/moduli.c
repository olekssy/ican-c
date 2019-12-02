#include <stdio.h>

int main(void) {
    int a, b;
    a = 1;
    b = 1;
    while (a > 0 && b > 0) {
        printf("Enter two operands: ");
        scanf("%i %i", &a, &b);
        printf("%i %% %i = %i\n", a, b, a%b);
    }
    printf("Done.\n");
    return 0;
}
