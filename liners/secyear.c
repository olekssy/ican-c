#include <stdio.h>
#define SEC_YEAR 3.156e7

int main(int argc, char const *argv[]) {
    unsigned age;

    printf("Enter your age in years: ");
    scanf("%u", &age);
    printf("\nYour age in seconds: %.3e\n", age*SEC_YEAR);

    return 0;
}
