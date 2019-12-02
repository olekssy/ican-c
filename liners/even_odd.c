#include <stdio.h>
#include <ctype.h>
#define ZERO 48 //code for '0'

int main(void) {
    char ch;
    int count_eve = 0;
    int count_odd = 0;
    int sum_eve = 0;
    int sum_odd = 0;
    float ave_eve, ave_odd;

    while ((ch = getchar()) != ZERO) {
        if (!isdigit(ch))
            continue;
        if (ch%2 == 0) {
            count_eve++;
            sum_eve += ch - ZERO;
        }
        else {
            count_odd++;
            sum_odd += ch - ZERO;
        }
    }
    if (count_eve)
        ave_eve = (float) sum_eve/count_eve;
    if (count_odd)
        ave_odd = (float) sum_odd/count_odd;
    printf("        even    odd\n");
    printf("Sum       %i     %i\n", sum_eve, sum_odd);
    printf("Count     %i     %i\n", count_eve, count_odd);
    printf("Mean      %.1f   %.1f\n", ave_eve, ave_odd);
}
