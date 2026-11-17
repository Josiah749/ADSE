#include <stdio.h>

int main(){
    int p=1200,t=2,r=5.4;
    float ci;
    ci=p*(1+r/100)^t;
    printf("%f",ci);
    return 0;
}