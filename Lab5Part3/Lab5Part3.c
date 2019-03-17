#include <stdio.h>

/*Program that calculates the day of the week given
  the day month and year*/

void inputDate(int *day, int *month, int *year);
void calculateDay(int day, int month, int year);

int main(int argc, char **argv){
    int day,month,year;
    inputDate(&day,&month,&year);
    calculateDay(day, month, year);

    return 0;
}

void inputDate(int *day, int *month, int *year){
    printf("Please enter a date: ");
    scanf("%d/%d/%d", day, month, year);
}
void calculateDay(int day, int month, int year){
    
    int A = month;
    int B = day;
    int D = year / 100;
    int C = year % 100;
    int W,X,Y,Z,R;
    
    if(A < 3) {
        A += 10;
        C = (year - 1)%100;
        D--;
    } else {
        A -= 2;
    }

    W = (13 * A - 1) / 5;
    X = C / 4;
    Y = D / 4;
    Z = W + X + Y + B + C - 2 * D;
    R = Z % 7;
    
    if(R<0){
        R+=7;
    }
    
    printf("The day %d/%d/%d is a ", day, month, year);
    
    if(R == 0){
        printf("Sunday.\n");
    } else if (R == 1) {
        printf("Monday.\n");
    } else if (R == 2) {
        printf("Tuesday.\n");
    } else if (R == 3) {
        printf("Wednesday.\n");
    } else if (R == 4) {
        printf("Thursday.\n");
    } else if (R == 5) {
        printf("Friday.\n");
    } else if(R == 6) {
        printf("Saturday.\n");
    } 
}