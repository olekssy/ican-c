/* header with constants and declarationsfor hotel.c */
#define QUIT 5
#define HOTEL1 180.0
#define HOTEL2 225.0
#define HOTEL3 255.0
#define HOTEL4 425.0
#define DISCOUNT 0.95

#define STARS "****************************************************"

// menu list
int menu(void);

// number of nights desired
int getnights(void);

// estimate price
void getprice(double rate, int nights);
