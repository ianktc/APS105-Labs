#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/* Program that simulates the game craps*/ 

int rollDice(void);
bool playGame(void);
void winLoss(void);

int main(){
    winLoss();
    return 0;
}

int rollDice(void){
    int roll1 = 0, roll2 = 0;
    int sum = 0;
    roll1 = (rand() % 6) + 1;
    roll2 = (rand() % 6) + 1;
    sum = roll1 + roll2;
    return sum;
}

bool playGame(void){
    int sum = 0;
    bool win = 0;
    
    sum = rollDice();
    int firstRoll = sum;
        
    printf("You rolled: %d\n", firstRoll);
    
    if(firstRoll == 7 || firstRoll == 11){
        printf("You win!\n");
        return true;
    }
    
    if(firstRoll == 2 || firstRoll == 3 || firstRoll == 12){
        printf("You lose!\n");
        return false;
    }
    
    printf("Your point is: %d\n", firstRoll);
    win = false;
    
    while(win == false){
        sum = rollDice();
        printf("You rolled: %d\n", sum);
        if(sum == 7){
            printf("You lose!\n");
            return false;
        }
        if (sum == firstRoll){
            win = true;
            printf("You win!\n");
        }
    }
    
    return true;
}
    
void winLoss(void){
    char input = 0, checker = 0;
    int wins = 0, losses = 0;
    do{
        if(playGame()){
            wins++;
        } else {
            losses++;
        }
        printf("Play again? "); //notice the space here, it was screwing up the program before!
        scanf(" %c%c", &input, &checker); //notice the space here, it was screwing up the program before!
        
        if (checker!=10)
            break;
        
    } while(input == 'y' || input == 'Y');
    
    if(input != 'y' || input != 'Y'){
        printf("\nWins: %d\nLosses: %d\n", wins, losses);
    }
}


