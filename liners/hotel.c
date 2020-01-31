/* functions for hotel management system */
#include <stdio.h>
#include "hotel.h"

int menu(void) {
    int code, status;
    printf("%s\n", STARS);
    printf(
        "Enter the number of the desired hotel:\n"
        "1) Fairfield Arms      2) Hotel Olympic\n"
        "3) Chertworthy Plaza   4) The Stockton\n"
        "5) quit\n"
    );
    printf("%s\n", STARS);
    while ((status = scanf("%i", &code)) != 1 || (code < 1 || code > 5)) {
        if (status != 1) {
            scanf("%*s");
        }
        printf("Enter an integer 1 < n < 5.\n");
    }
    return code;
}

int getnights(void) {
    int status, n;
    printf("How many nights are needed?\n");
    while ((status = scanf("%i", &n)) != 1 || (n < 0 || n > 100)) {
        if (status != 1) {
            scanf("%*s");
        }
        printf("Enter non-negative integer.\n");
    }
    return n;
}

void getprice(double rate, int nights) {
    double total = 0.0;
    double factor = 1.0;
    for (int n = 1; n <= nights; n++, factor *= DISCOUNT) {
        total += rate * factor;
    }
    printf("The total cost will be $%0.2f.\n", total);
}
