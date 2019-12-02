// provide time delay in ms
#include <stdio.h>
#include <time.h>

void delay(int dt) {
    clock_t t0 = clock();
    while (clock() < t0 + dt)
        ;
}
