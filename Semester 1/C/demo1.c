#include <stdio.h>
int main() {
    float principal=100000,rate=3,time=7;
    float simple_interest;
    simple_interest=(principal*rate*time)/100;
    printf("%f",simple_interest);
    return 0;
}