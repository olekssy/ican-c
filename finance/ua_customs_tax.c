/* Ukrainian customs import tax 2020 */
#include <stdio.h>

#define BASE 100
#define BASE_MYTO 150
#define RATE_VAT .20
#define RATE_MYTO .10
#define UAH_EUR 33.49
#define UAH_USD 28.34
#define BROKER_FEE 520.0

int main(void) {
    float price;
    float myto = 0;
    float tax;
    float fee = 0.0;

    printf("=== UA import tax & fees calculator ===\n");
    printf("Enter price in USD: ");
    scanf("%f", &price);
    
    // convert price to EUR
    price = price * UAH_USD / UAH_EUR;

    // calculate import tax and fees
    if (price <= BASE) {
        tax = 0;
    }
    else if (price > BASE && price < BASE_MYTO) {
        tax = (price - BASE) * RATE_VAT;
        fee = BROKER_FEE;
    }
    else {
        myto = (price - BASE_MYTO) * RATE_MYTO;
        tax = (price - BASE + myto) * RATE_VAT;
        fee = BROKER_FEE;
    }

    // display results
    printf("Price: %.2f UAH\n", price * UAH_EUR);
    printf("+ myto: %.2f UAH\n", myto * UAH_EUR);
    printf("+ tax: %.2f UAH\n", tax * UAH_EUR);
    printf("+ broker fee: %.2f UAH\n", fee);
    printf("= %.2f UAH = %.2f USD\n",
            (price + myto + tax) * UAH_EUR + fee,
            ((price + myto + tax) * UAH_EUR + fee) / UAH_USD);

    printf("Effective rate: %.2f %%\n", (
                ((price + myto + tax) * UAH_EUR + fee) 
                / (price * UAH_EUR)
                - 1)  * 100.0); 

    printf("\nUAH/EUR = %.2f\n", UAH_EUR);
    printf("UAH_USD = %.2f\n", UAH_USD);
 
    return 0;
}
