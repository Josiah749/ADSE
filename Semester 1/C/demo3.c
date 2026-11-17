#include<stdio.h>
int main(){
    char choice;
    float loan = 5000;
    printf("1:Buy Data\n2:Buy Airtime\n3:Borrow Airtime\n");
    printf("4:Pay Back Loan\n*:Next\n\nEnter Option:");

    // scanf("%c",&choice);
    choice = getchar();

    if(choice == '1'){
        printf("You have select to buy data");
    }else if(choice == '2'){
        printf("You have select to buy airtime");
    }else if(choice == '3'){
        printf("You have select to borrow airtime");
    }else if(choice =='4')
        printf("You have select to pay back loan...\n\n");
   
        
        
        float credit_balance;
        printf("Enter value:");
        scanf("%f",&credit_balance);


        if (credit_balance<=0)
            printf("Loan repayment can not be zero or less!");
        else if (credit_balance > loan){
            credit_balance -= loan;
            loan = 0;
            printf("You have successfully paid back\n");
            printf("current credit balance is%f\n",credit_balance);
            printf("current loan balance is%f\n",loan);
        }
        else if (credit_balance < loan){
            loan -= credit_balance;
            credit_balance = 0;
            printf("current credit balance is: %f",credit_balance);
            printf("current loan balance is: %f",loan);
        }
    else if(choice =='*'){
        printf("Go to the next screen... ");
    }else {
        printf("Invalid option");            
    }
    return 0;
}