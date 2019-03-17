#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*program that encrypts a five or greater digit number using two
 forms of encryption (adding four and shfiting by one) */

void input(int *num);
int add4 (int num);
int shift (int intermediaryNum);
void printOutput (int encryptNum, int originalNum);

int main(){
    int num = 0;
    int intermediaryNum = 0;
    int encryptNum = 0;
    int originalNum = 0;
    
    input(&num);
    intermediaryNum = add4(num);
    encryptNum = shift(intermediaryNum);
    originalNum = num;
    printOutput(encryptNum, originalNum);
}

void input(int *num){
    //function to check for valid input, and stores the user input in num
    do {
        printf("Please enter an integer greater than 99999: ");
        scanf("%d", num);
        if(*num < 99999){
            printf("Incorrect input\n");
        }
    } while (*num < 99999);
    
    printf("The number entered is %d\n", *num);
}

int add4(int num){
    //function to add four to num
    
    int lastDigit = 0;
    int digit = 0;
    int totalDigits = 0;
    //stores the result in variable called intermediaryNum rather than num
    int intermediaryNum = 0;
    
    //finds the value of last digit, while also checking if > 9
    lastDigit = (num % 10) + 4;
        if(lastDigit > 9){
            lastDigit -= 10;
        }
    //finds the values of all other digits
    for(int i = 10; i < num; i*=10){
        digit = (num / i) % 10 + 4;
            if(digit > 9){
                digit -= 10;
            }
        //sums the digits excluding last digit to equal into a integer
        totalDigits += digit*i;
    }
    //adds in last digit to equal the intermediaryNum
    intermediaryNum = totalDigits + lastDigit;
    return intermediaryNum;
}

int shift (int intermediaryNum){
    //function to shift all digits one place,
    //making the first digit the ones digit
    int firstDigit = 0;
    int choppedNum = 0;
    int numDigits = 0;
    int encryptNum = 0;
    //use temps to find first digit and number of digits
    int temp = intermediaryNum;
    int temp2 = intermediaryNum;
    
    //find number of digits
    while(temp != 0){
        temp /= 10;
        numDigits++;
    }
  
    //find the first digit
    do {
        firstDigit = (int) (temp2/10);
        temp2 = firstDigit;
    } while(firstDigit > 10);
    
    //finding the number wihtout the first digit, and appending the first digit to end
    choppedNum = intermediaryNum - firstDigit * pow(10,numDigits-1);
    encryptNum = choppedNum*10 + firstDigit;
    return encryptNum;
}

void printOutput (int encryptNum, int originalNum){
    printf("Original number: %d\n", originalNum);
    printf("Encrypted number: %d\n", encryptNum);
}