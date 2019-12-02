#include <stdio.h>
#define HR 60

int main(void) {
    int mins, hrs;
    mins = 1;
    while (mins > 0) {
        printf("Enter time in minutes (parse 0 to quit): ");
        scanf("%i", &mins);
        printf("%i hours %i minutes\n", mins/HR, mins%HR);
    }
    return 0;
}
