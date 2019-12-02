#include <stdio.h>
//earning rates
#define PAY_R1 8.75
#define PAY_R2 9.33
#define PAY_R3 10.0
#define PAY_R4 11.2

#define QUIT '5'

#define OVER_HRS 40.0
#define OVER_MULT 1.5
#define TAX_R1 .15
#define TAX_R2 .2
#define TAX_R3 .25
#define TAX_B1 300.0
#define TAX_B2 150.0

int main(void) {
    char opt;
    float pay_base = 0;
    float pay_over;
    float pay_gross, pay_net;
    float tax;
    float hours;
    //select base pay $/hr
    printf(
            "*****************************************************************\n"
            "Enter the number corresponding to the desired pay rate or action:\n"
            "1) $%.2f/hr \t\t\t2) $%.2f/hr\n"
            "3) $%.2f/hr \t\t\t4) $%.2f/hr\n"
            "5) quit\n"
            "*****************************************************************\n",
            PAY_R1, PAY_R2, PAY_R3, PAY_R4);
    while ((opt = getchar()) != QUIT) {
        switch (opt) {
            case '1': pay_base = PAY_R1; break;
            case '2': pay_base = PAY_R2; break;
            case '3': pay_base = PAY_R3; break;
            case '4': pay_base = PAY_R4; break;
            case '\n': break; //to avoid printing 'default' twice
            default : printf("Enter 1-4, enter 5 to quit\n"); break;
        }
        if (pay_base)
            break;
    }
    //check pay_base validity before proceeding
    if (pay_base) {
        pay_over = pay_base*OVER_MULT;
        //Enter hrs worked
        printf("Enter hrs worked: ");
        while (scanf("%f", &hours)) {
            //calc gross pay
            if (hours > OVER_HRS)
                pay_gross = (hours - OVER_HRS)*pay_over + OVER_HRS*pay_base;
            else
                pay_gross = hours*pay_base;
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
            printf("Gross pay \t$%5.2f\n", pay_gross);
            printf("Tax paid \t$%5.2f\n", tax);
            printf("Net pay \t$%5.2f\n", pay_net);
            printf("\nEnter hrs worked (q to quit): ");
        }
    }
    return 0;
}
