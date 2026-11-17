#include<stdio.h>
int main(){
    float PIE = 3.142, R, AREA, PERIMETER;
    float *ptr_PIE, *ptr_R, *ptr_AREA, *ptr_PERIMETER;
    
    AREA = PIE*R*R;
    PERIMETER = 2*PIE*R;


    ptr_PIE = &PIE;
    ptr_R = &R;
    ptr_PERIMETER = &PERIMETER;
    ptr_AREA = &AREA;

    AREA = (*ptr_PIE) * (*ptr_R) * (*ptr_R);
    PERIMETER = 2 * (*ptr_PIE) * (*ptr_R);
    
    printf("Enter Radius: ");
    scanf("%f", ptr_R);

    printf("AREA: %f", *ptr_AREA);
    return 0; 
}