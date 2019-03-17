#include <stdio.h> //including necessary libraries
#include <math.h>

int main(void){
	double num1, num2, product, difference, sumSqrt; //declaring variables
    printf("Enter two positive numbers: \n"); //printing a statement that requests two positive numbers
    scanf("%lf %lf", &num1, &num2); //storing two inputted numbers in memory

    product = (num1 * num2); //calculating product 
    difference = num1 - num2; //calculating difference
    sumSqrt = sqrt(num1) +sqrt(num2); //calculating the sum of the square roots
    printf("The product is: %0.2lf, the difference is: %0.2lf and the sum of roots is: %0.2lf\n", product, difference, sumSqrt); //printing the results
	return 0;
}