#include<stdio.h>

int square(int x);


int main(){
    int i;

    for(i = 1; i <=10; i++){
        int j;
        j = square(i);
        printf("square of %d is: %d\n", i, j);
    }

    // // Display the arranged list of strings
    // printf("\nRecorded list of strings :\n");
    // for (i = 0; i < n; ++i){
    //     printf("string %d is %s\n", i + 1, x[i]);
    // }
    return 0;
}
int square(int x){
    return (x * x);
}