/* hotel management system */
#include <stdio.h>
#include "hotel.h"

int main(void) {
    int nights, code;
    double hotel_rate;

    while ((code = menu()) != QUIT) {
        switch(code) {
            case 1:
                    hotel_rate = HOTEL1;
                    break;
            case 2:
                    hotel_rate = HOTEL2;
                    break;
            case 3:
                    hotel_rate = HOTEL3;
                    break;
            case 4:
                    hotel_rate = HOTEL4;
                    break;
            default:
                    hotel_rate = 0.0;
                    printf("Unexpected error occured");
                    break;
        }
        nights = getnights();
        getprice(hotel_rate, nights);
    }
    printf("Done.\n");
    return 0;
}
