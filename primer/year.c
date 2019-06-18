#include <stdio.h>

// the program prompts user for the year of births,
// calculates age in years, returns age in days

int main(void) {

  int year;
  int age;

  printf("Enter the year you were born: ");
  scanf("%d", &year);

  age = 2019 - year;
  printf("In 2019 you are %d years old, ", age);
  printf("that equals to %d days\n", age * 365);

  return 0;
}
