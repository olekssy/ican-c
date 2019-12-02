#include <stdio.h>
#define PAY_BASE 10.0
#define OVER_HRS 40.0
#define OVER_MULT 1.5
#define PAY_OVER PAY_BASE*OVER_MULT
#define TAX_R1 .15
#define TAX_R2 .2
#define TAX_R3 .25
#define TAX_B1 300.0
#define TAX_B2 150.0

int main(void) {
    float pay_gross, pay_net;
    float tax;
    float hours;
    printf("Enter hrs worked: ");
    while (scanf("%f", &hours)) {
        //calc gross pay
        if (hours > OVER_HRS)
            pay_gross = (hours - OVER_HRS)*PAY_OVER + OVER_HRS*PAY_BASE;
        else
            pay_gross = hours*PAY_BASE;
        //calc taxes
        if (pay_gross < TAX_B1) //under $300
            tax = pay_gross*TAX_R1;
        else if (pay_gross > TAX_B1 && pay_gross < (TAX_B1+TAX_B2)) //$300 < x < $450
            tax = TAX_B1*TAX_R1 + (pay_gross-TAX_B1)*TAX_R2;
        else if (pay_gross > (TAX_B1+TAX_B2)) //over $450
            tax = TAX_B1*TAX_R1
                + TAX_B2*TAX_R2
                + (pay_gross-TAX_B1-TAX_B2)*TAX_R3;
        //calc net pay, display results
        pay_net = pay_gross - tax;
        printf("Gross pay = %.2f\n", pay_gross);
        printf("Tax paid = %.2f\n", tax);
        printf("Net pay = %.2f\n", pay_net);
        printf("Enter hrs worked (q to quit): ");
    }
    return 0;
}
