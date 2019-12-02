#include <stdio.h>

int main(void) {
    int days, sum=0, i=0;
    printf("Enter num of days: ");
    scanf("%i", &days);

    while (i++ < days) {
        sum += i;
    }
    printf("Sum = %i\n", sum);
    return 0;
}
