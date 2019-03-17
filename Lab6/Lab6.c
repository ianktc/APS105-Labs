#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

void printBoard(int board[], int playerA, int playerB);
int requestValidInput(int board[], int playerA, int playerB);
int checkForWinner(int board[], int playerA, int playerB);

int main(void) {
    //setting board array and player values
    int board [MAX] = {'1','2','3','4','5','6','7','8','9'};
    int playerA = 'A';
    int playerB = 'B';

    printBoard(board, playerA, playerB);

    return 0;
}
 
void printBoard(int board[], int playerA, int playerB){    
    //state variable indicates state of game
    //moves increments to observe tie
    bool state = false; 
    int moves = 0;
    
    //for loop to alternate turns
    for(int j = 0; !state; j++){ 
        printf("The current state of the Tic-tac-toe Board:\n\n");
   
        //assigns each element a number from 1 to 9
        //also makes a new line after every three elements
        for(int i = 0; i < 9 ; i++){ 
            printf("%c ",board[i]); 
            if((i + 1) % 3 == 0) printf("\n"); 
        }
        
        if(!(j % 2)) printf("\nIt is player A's turn.\n");
        else printf("\nIt is player B's turn.\n");
    
        //prints the letter over the number on the board
        int result = requestValidInput(board, playerA, playerB);
        if(!(j % 2)) {
            board[result-1] = playerA;
            moves++;
        } else { 
            board[result-1] = playerB;
            moves++;
        }
            
        //checking state of game
        int winner = checkForWinner(board, playerA, playerB);
        if (winner == 1) {
            printf("Player A wins!\n\n");
            state = true;
        } else if (winner == 2) {
            printf("Player B wins!\n\n");
            state = true;
        } else if (moves > 8) {
            printf("It's a draw!\n\n");
            state = true;
        }                
    }
     
    //print final board
    for(int i = 0; i < 9 ; i++) { 
        printf("%c ",board[i]); 
        if((i + 1) % 3 == 0) printf("\n"); 
    }   
    printf("\n");
}

int requestValidInput(int board[], int playerA, int playerB){
    int input;
    
    printf("Please enter a valid position to play.\n");
    scanf(" %d", &input);
    
    while(input < 1 || input > 9){
        printf("Invalid input, please try again.\n");
        scanf(" %d", &input);
    }
    
    while(board[input - 1] == 'A' || board[input - 1] == 'B'){
        printf("That position has already been played, please try again\n");
        scanf(" %d", &input);
    }
   
    return input; 
}

int checkForWinner(int board[], int playerA, int playerB) {
    int winnerA = 1;
    int winnerB = 2;
    int cont = 3;
    
    //for loop to test rows
    for(int i = 0; i < 7; i+=3){
        if(board[i] == playerA && board[i+1] == playerA && board[i+2] == playerA){
            return winnerA;
        } else if(board[i] == playerB && board[i+1] == playerB && board[i+2] == playerB){
            return winnerB;
        }
    }
    
    //for loop to test columns
    for(int j = 0 ; j < 3; j ++){    
        if(board[j] == playerA && board[j+3] == playerA && board[j+6] == playerA){
            return winnerA;
        } else if (board[j] == playerB && board[j+3] == playerB && board[j+6] == playerB){
            return winnerB;
        }
    }
    
    //for loop to test diagonals
    //negative slope
    if(board[0] == playerA && board[4] == playerA && board[8] == playerA){
        return winnerA;
    } else if(board[0] == playerB && board[4] == playerB && board[8] == playerB){
        return winnerB;
    }
    
    //positive slope
    if(board[2] == playerA && board[4] == playerA && board[6] == playerA){
        return winnerA;
    } else if(board[2] == playerB && board[4] == playerB && board[6] == playerB){
        return winnerB;
    }
    
    return cont; 
}