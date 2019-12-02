#include <stdio.h>

#define WEEK 7

int main(void) {
    int days=1;
    while (days > 0) {
        printf("Enter days: ");
        scanf("%i", &days);
        printf("%i days are %i week(s) and %i day(s)\n", days, days/WEEK, days%WEEK);
    }
    return 0;
}
