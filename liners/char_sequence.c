#include <stdio.h>
#define END '#'
#define E 'e'
#define I 'i'

int main(void) {
    char ch, chp;
    int count;
     while ((ch = getchar()) != END) {
         if (chp == E && ch == I) {
             count++;
         }
         chp = ch;
     }
     printf("'ei' count: %i\n", count);
     return 0;
}
