#include <stdio.h>

int main(void) {
    int iin, stop;
    printf("Enter number: ");
    scanf("%i", &iin);
    stop = iin + 10;
    iin--;
    while (iin++ < stop) {
        printf("%i ", iin);
    }
    printf("\n");
    return 0;
}
