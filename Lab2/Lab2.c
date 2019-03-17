#include <stdio.h>
#include <math.h>

int main(void){
    
    int months; double interest, monthlyPayment, purchasePrice, totalPrice;
    
    printf("Enter the purchase price of the item: ");
    scanf("%lf", &purchasePrice);
    printf("Enter the interest rate per year as a percentage: ");
    scanf("%lf", &interest);
    printf("Enter the number of months for repayment: ");
    scanf("%d", &months);
    
    interest/= 1200;
    monthlyPayment = (interest*purchasePrice)/(1 - pow(1 + interest, -months));
    totalPrice = months * monthlyPayment;
        
    printf("The monthly payment is: %0.2lf.\nThe total price is: %0.2lf\n", monthlyPayment, totalPrice);
    
    return 0;
}
