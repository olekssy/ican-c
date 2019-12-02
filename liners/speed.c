#include <stdio.h>

#define BYTE 8

int main(void) {
    float speed, size;
    printf(
        "Enter download speed (Mbs) "
        "and file size (MB): "
        );
    scanf("%f %f", &speed, &size);
    printf(
        "At %.2f megabits per second, a file of " "%.2f\n" "megabytes downloads in %.2f " "seconds.\n",
        speed, size, size/speed);
    return 0;
}
