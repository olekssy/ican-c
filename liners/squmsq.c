#include <stdio.h>

int main(void) {
    int i, d, sum;
    sum = 0;
    i = 0;
    printf("Enter num of days: ");
    scanf("%i", &d);
    while (i++ < d) {
        sum += i*i;
    }
    printf("Sum of squares = %i\n", sum);
    return 0;
}
