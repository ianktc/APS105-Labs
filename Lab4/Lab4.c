#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

/* write a program that calculates riemann sum for function: y = 2x^2 - 7x - 2 */

double EvalFunc(double n);
bool validateInputs(double a, double b, double n);

//user inputs
double n = 0; double a = 0; double b = 0;

//riemann sum variables
double stepSize = 0;
double xStar = 0;
double area = 0;
double result = 0;
double totalAreaLeft = 0, totalAreaRight = 0, totalAreaMiddle = 0;
bool valid = 0;

int main(){
    
    do {
        
        printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\nTo exit enter 0 0 0 \n");
        scanf("%lf%lf%lf", &a, &b, &n);
    
        valid = validateInputs(a,b,n);
    } while (valid == false);
     
    for(int i = 1; i<=n; i++){              
    xStar = a + ((i - 1)* stepSize);
    area = EvalFunc(xStar);
    totalAreaLeft += area;
    }
    
    for(int i = 1; i<=n; i++){              
    xStar = a + ((i - 0.5)* stepSize);
    area = EvalFunc(xStar);
    totalAreaMiddle += area;
    }
        
    for(int i = 1; i<=n; i++){              
    xStar = a + (i * stepSize);
    area = EvalFunc(xStar);
    totalAreaRight += area;
    }
    
    printf("With Step Size: %0.4lf\n", stepSize);
    printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
    printf("Bound between %0.2lf and %0.2lf, using %d rectangles is as follows\n\n", a, b, ((int)n));
    printf("Mid point evaluation approximate: %0.4lf\nLeft point evaluation approximate: %0.4lf\nRight point evaluation approximate: %0.4lf\n", 
    totalAreaMiddle, totalAreaLeft, totalAreaRight);    
    
    return 0;    
}

bool validateInputs(double a, double b, double n){
    
    if (a == 0 && b == 0 && n ==0){
        printf("Invalid inputs...\n\nTerminating main!\n");
        return 0;
    }
        
    if (b <=a || a <-10.0 || b > 10.0 || n <= 0 || (int) n != n){
        printf("Invalid inputs...\n\n");
        return false;
    }

    stepSize = (b-a)/n;
    return true;
}

double EvalFunc(double n){
    result = (2*pow(xStar,2) - 7*xStar- 2) * stepSize;    
    return result;
}