/* Canadian personal income tax calculator  2020 tax rates */
#include <stdio.h>

// income threshold
#define BASE 48535
#define U100K 97069
#define U150K 150473
#define U200K 214368

// tax rates
#define TAX_BASE .15
#define TAX_U100K .205
#define TAX_U150K .26
#define TAX_U200K .29
#define TAX_MAX .33

int main(void) {
    float income;
    float taxes;
    float net_income;

    printf("Enter level of annual income: ");
    scanf("%f", &income);

    // calculate taxes;
    if (income < BASE) { // income < 50k
        taxes = income * TAX_BASE;
    }
    else if (income > BASE && income < U100K) { // 50k < income < U100K
        taxes = BASE * TAX_BASE + (income - BASE) * TAX_U100K;
    }
    else if (income > U100K && income < U150K) { // U100K < income < U150K
         taxes = BASE * TAX_BASE + (U100K - BASE) * TAX_U100K + (income - U100K) * TAX_U150K;
    }
    else if (income > U150K && income < U200K) { // U150K < income < U100K
         taxes = BASE * TAX_BASE + (U100K - BASE) * TAX_U100K + (U150K - U100K) * TAX_U150K + (income - U150K) * TAX_U200K;
    }
    else { // income > U200K
        taxes = BASE * TAX_BASE + (U100K - BASE) * TAX_U100K + (U150K - U100K) * TAX_U150K + (U200K - U150K) * TAX_U200K + (income - U200K) * TAX_MAX;
    }

    // calculate a-tax income, display results
    net_income = income - taxes;
    printf("Gross income = %.2f\n", income);
    printf("PI taxes = %.2f\n", taxes);
    printf("Net income = %.2f\n", net_income);
    printf("Net income per month = %.2f\n", net_income / 12);

    return 0;
}
