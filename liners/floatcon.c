#include <stdio.h>

int main(int argc, char const *argv[]) {
    float fin;
    printf("Enter float: ");
    scanf("%f", &fin);

    printf("\nFixed point: %f\n", fin);
    printf("Exp: %e\n", fin);
    printf("Hex float %a\n", fin);
    return 0;
}
