#include <stdio.h>
#include <math.h>

/*program that calculates the number of coupons that someone can get from buying coffee
as well as the number of free coffees (use loop)*/

int main(void){
    
    //inputted values from user
    double cost = 0; 
    double budget = 0;
    int couponsRequired = 0;
    
    //variables that depend on the user input
    int numCoffees = 0;
    int numCoupons = 0;
    int freeCoffee = 0;
    int remainingCoupons = 0;
    int totalCoffee = 0;
    int totalFreeCoffee = 0;
    double remainingBalance = 0;
    double averageCost = 0;
    
    //receiving input from the user, and ensuring valid input
    printf("How much does a coffee cost?\n");
    scanf("%lf", &cost);
    
    if (cost < 0.01) {
        printf("Invalid Input\n"); 
    }

    printf("How many coupons does it take to get a free coffee?\n");
    scanf("%d", &couponsRequired);
    
    if (couponsRequired <= 0 || (couponsRequired - (int)couponsRequired) !=0 ) {
        printf("Invalid Input\n");   
    }
    
    printf("How much money do you have to spend on coffee this month?\n");
    scanf("%lf", &budget);
    
    if (budget <= 0) {
        printf("Invalid Input\n");  
    }
    
    //loop and computations begin
    
    //these are static values, they should not change after the user inputs
    numCoffees = budget / cost;
    numCoupons = numCoffees;
    remainingBalance = budget - (numCoffees * cost);
    
    //the if statement will test if the user can redeem coupons
    if (numCoupons >= couponsRequired) {
        
        while (numCoupons >= couponsRequired) { 
            
            freeCoffee = numCoupons / couponsRequired;                      //finding initial number of free coffees
            remainingCoupons = freeCoffee + (numCoupons % couponsRequired); //finding the number of coupons left (given the free coffees, and unused coupons)
            numCoupons = remainingCoupons;                                  //resetting numCoupons to remainingCoupons
            totalFreeCoffee += freeCoffee;                                  //tallying the number of free coffees using a seperate variable
        }
    
    totalCoffee = totalFreeCoffee + numCoffees;                   //finding total number of coffees
    averageCost = (budget - remainingBalance) / totalCoffee;      // finding average cost (including free coffees in average)
    
    printf("This month, you can purchase %d coffees at $%0.2lf each.\n", numCoffees, cost);
    printf("You will be able to redeem an additional %d coffee(s) from coupons.\n", totalFreeCoffee);
    printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining. \n", remainingBalance, remainingCoupons);
    printf("On average, you have spent $%0.2lf on each cup of coffee this month.\n", averageCost);
    
    } else {                                                       // else statement will execute if user cant redeem any coupons
    
    averageCost = (budget - remainingBalance) / numCoffees;        // finding average cost (excluding free coffees)
    
    printf("This month, you can purchase %d coffees at $%0.2lf each.\n", numCoffees, cost);
    printf("You will not be able to redeem any additional free coffees from coupons this month.\n");
    printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining. \n", remainingBalance, numCoupons);
    printf("On average, you have spent $%0.2lf on each cup of coffee this month.\n", averageCost);
    
    }
    
    return 0;
}