#include <stdio.h>
#define MOL_MASS 3.0e-23
#define Q_MASS 950

int main(void) {
    float vol;
    printf("Enter amount of water in quarts: ");
    scanf("%f", &vol);

    printf("There are %.2e molecules in %.2f grams of water\n",
            vol*Q_MASS/MOL_MASS, vol*Q_MASS);
    return 0;
}
