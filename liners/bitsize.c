#include <stdio.h>
// check bit size of data types

int main(void) {
    printf("short size %zd bytes\n", sizeof(short));
    printf("int size %zd bytes\n", sizeof(int));
    printf("long size %zd bytes\n", sizeof(long));
    printf("long long size %zd bytes\n", sizeof(long long));
    printf("float size %zd bytes\n", sizeof(float));
    printf("double size %zd bytes\n", sizeof(double));
    printf("long double size %zd bytes\n", sizeof(long double));
    printf("complex float size %zd bytes\n", sizeof(_Complex float));
    printf("int size %zd bytes\n", sizeof(_Complex double));
    printf("complex long double size %zd bytes\n", sizeof(_Complex long double));
    printf("char size %zd bytes\n", sizeof(char));
    printf("_Bool size %zd bytes\n", sizeof(_Bool));
}
