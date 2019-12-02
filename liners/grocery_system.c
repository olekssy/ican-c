#include <stdio.h>

float getWeight(float w);
float getPrice(float w, float p);

int main(void) {
    //price per pound
    const float ARTICHOKES = 20.05;
    const float BEETS = 1.15;
    const float CARROTS = 1.09;
    //discounts
    const float BIG_ORDER = 100.0;   // in $
    const float DISCOUNT = .05;     //for BIG_ORDER
    //shipping weights and rates
    const float LIGHT = 5.0;
    const float HEAVY = 20.0;
    const float SHIP_LOW = 6.5;    //LIGHT weight flat rate
    const float SHIP_MED = 14.0;   //LIGHT to HEAVY flat rate
    const float SHIP_HIGH = .5;    //for extra pound over HEAVY
    const char QUIT = '4';

    char opt;
    //ordered weight
    float a = 0.0; //ARTICHOKES
    float b = 0.0; //BEETS
    float c = 0.0; //CARROTS
    //total price per item
    float ap = 0.0;
    float bp = 0.0;
    float cp = 0.0;
    float t_weight, t_price, grand_total;    //total weight and price
    float savings = 0.0;
    float shipping = 0.0;

    printf(
        "Select item from the list\n"
        "1) Artichokes \t$%.2f/lb;\n"
        "2) Beets \t$%.2f/lb;\n"
        "3) Carrots \t$%.2f/lb;\n"
        "4) Proceed to checkout.\n",
        ARTICHOKES, BEETS, CARROTS
    );
    while ((opt = getchar()) != QUIT) {
        switch (opt) {
            case '1': a = getWeight(a); ap = getPrice(a, ARTICHOKES); break;
            case '2': b = getWeight(b); bp = getPrice(b, BEETS); break;
            case '3': c = getWeight(c); cp = getPrice(c, CARROTS); break;
            case '\n': break;
            default : printf("Select from available options.\n");
        }
    }
    //shipping costs
    t_weight = a + b + c;
    if (!t_weight)
        printf("Nothing ordered.\n");
    if (t_weight < LIGHT)
    shipping = SHIP_LOW;
    else if (t_weight > LIGHT && t_weight < HEAVY)
    shipping = SHIP_MED;
    else if (t_weight > HEAVY)
    shipping = SHIP_MED + (t_weight - HEAVY)*SHIP_HIGH;
    // calc discount before shipping costs
    t_price = ap + bp + cp;
    if (t_price >= BIG_ORDER)
        savings = t_price * DISCOUNT;
    grand_total = t_price - savings + shipping;
    //display results
    printf("===Order Summary===\n");
    //display items selectively
    if (a)
        printf("Artichokes  %4.2f lb | $%.2f\n", a, ap);
    if (b)
        printf("Beets       %4.2f lb | $%.2f\n", b, bp);
    if (c)
        printf("Carrots     %4.2f lb | $%.2f\n", c, cp);
    printf("\nTotal Price: \t$%.2f\n", t_price);
    printf(
        "Savings: \t$%.2f\n"
        "Shipping: \t$%.2f\n"
        "Grand TOTAL: \t$%.2f\n"
        "Have a good day!\n",
        savings, shipping, grand_total
    );

    return 0;
}

float getWeight(float w) {
    float add_w;
    printf("Enter weight desired (q to quit): ");
    while (scanf("%f", &add_w)) {
        if (add_w < 0 && -add_w > w)
            w = 0;
        else
            w += add_w;
        printf("Total weight of item: %.2f pounds.\n", w);
        printf("Select another item from the list\n");
        break;
    }
    return w;
}

float getPrice(float w, float p) {
    float tp = 0.0; //total price
    if (w > 0) {
        tp = w*p;
    }
    return tp;
}
