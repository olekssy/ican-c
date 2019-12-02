#include <stdio.h>

void temperatures(float t);

int main(void) {
    float temp;
    printf("Enter temp in F (q to quit): ");
    while (scanf("%f", &temp) == 1) {
        temperatures(temp);
        printf("Enter temp in F (q to quit): ");
    }
    return 0;
}

void temperatures(float t) {
    const float SCALE = 5.0/9.0;
    const float F_LEVEL = 32.0;
    const float K_LEVEL = 273.16;
    float c;
    c = SCALE*(t - F_LEVEL);
    printf("Celsius = %5.2f \nKelvin = %5.2f\n", c, c + K_LEVEL);
}
