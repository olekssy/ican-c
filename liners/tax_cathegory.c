#include <stdio.h>

//income threshold
#define INC_SING 17850.0
#define INC_HEAD 23900.0
#define INC_MARR 29750.0
#define INC_SEPA 14875.0
//tax rates
#define TAX_BASE .15
#define TAX_EXCE .28

#define QUIT '5'

int main(void) {
    char cat;
    float income, tax;
    float inc_base = 0;
    //get user tax income chathegory
    printf("Select from options: \n1) Single \n2) Head of HS \n3) Married \n4) Divorced \n5) Quit\n");
    while ((cat = getchar()) != QUIT) {
        switch (cat) {
            case '1': inc_base = INC_SING; break;
            case '2': inc_base = INC_HEAD; break;
            case '3': inc_base = INC_MARR; break;
            case '4': inc_base = INC_SEPA; break;
            case '\n': break;
            default : printf("Select from 1-4, or enter 5 to quit\n");
        }
        if (inc_base) {
            //get taxable income
            printf("Enter taxable income (q to go back): ");
            while (scanf("%f", &income)) {
                if (income < inc_base)
                    tax = income*TAX_BASE;
                else
                    tax = inc_base*TAX_BASE + (income - inc_base)*TAX_EXCE;
                printf("Tax due: $%.2f\n", tax);
                //reset inc_base to get out from loop
                inc_base = 0;
                printf("Enter taxable income (q to go back): ");
            }
        }
    }
    return 0;
}
