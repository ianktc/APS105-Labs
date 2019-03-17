#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX 26

int getSize(int n);
char initializeBoard(char board[MAX][MAX], int size);
char printBoard(char board[MAX][MAX], int n);
char boardConfig(char board[MAX][MAX]);

bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[MAX][MAX], int n, int row, int col, char colour, int deltaRow, int deltaCol);

void flipTiles(char board[MAX][MAX], char colour, int row, int col, int deltaRow, int deltaCol);

int main() {
    int n = 0;
    char colour,row,col;
    char board[MAX][MAX] = {};
    bool valid = false;
    
    //prints intitial board setup with given size and given parameters
    n = getSize(n);
    initializeBoard(board,n);
    printBoard(board, n);
    boardConfig(board);
    printBoard(board, n);
     
    //for white
    printf("Available moves for W:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            //implement for loop later
            if(checkLegalInDirection(board, n, i, j, 'W', 1, 0)) printf("%c%c\n",i+97,j+97); // DOWN 
            if(checkLegalInDirection(board, n, i, j, 'W', -1, 0)) printf("%c%c\n",i+97,j+97); //UP
            if(checkLegalInDirection(board, n, i, j, 'W', 0, 1)) printf("%c%c\n",i+97,j+97); //RIGHT
            if(checkLegalInDirection(board, n, i, j, 'W', 0,-1)) printf("%c%c\n",i+97,j+97); //LEFT
            
            if(checkLegalInDirection(board, n, i, j, 'W', -1, -1)) printf("%c%c\n",i+97,j+97); //NW
            if(checkLegalInDirection(board, n, i, j, 'W', 1, 1)) printf("%c%c\n",i+97,j+97); //SE
            if(checkLegalInDirection(board, n, i, j, 'W', 1, -1)) printf("%c%c\n",i+97,j+97); //SW
            if(checkLegalInDirection(board, n, i, j, 'W', -1, 1)) printf("%c%c\n",i+97,j+97); //NE
        }
    }
    
    //for black    
    printf("Available moves for B:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            //implement for loop later
            if(checkLegalInDirection(board, n, i, j, 'B', 1, 0)) printf("%c%c\n",i+97,j+97); // DOWN 
            if(checkLegalInDirection(board, n, i, j, 'B', -1, 0)) printf("%c%c\n",i+97,j+97); //UP
            if(checkLegalInDirection(board, n, i, j, 'B', 0, 1)) printf("%c%c\n",i+97,j+97); //RIGHT
            if(checkLegalInDirection(board, n, i, j, 'B', 0,-1)) printf("%c%c\n",i+97,j+97); //LEFT
                      
            if(checkLegalInDirection(board, n, i, j, 'B', -1, -1)) printf("%c%c\n",i+97,j+97); //NW
            if(checkLegalInDirection(board, n, i, j, 'B', 1, 1)) printf("%c%c\n",i+97,j+97); //SE
            if(checkLegalInDirection(board, n, i, j, 'B', 1, -1)) printf("%c%c\n",i+97,j+97); //SW
            if(checkLegalInDirection(board, n, i, j, 'B', -1, 1)) printf("%c%c\n",i+97,j+97); //NE
        }
    }
    
    //single move validation
    printf("Enter a move: \n");
    scanf(" %c%c%c", &colour,&row,&col);
    
    if(checkLegalInDirection(board, n, row - 97, col - 97, colour, 1, 0)) {
        flipTiles(board, colour, row - 97,col - 97,1,0); 
        valid = true;
    }
    if(checkLegalInDirection(board, n, row - 97, col - 97, colour, -1, 0)) {
        flipTiles(board, colour, row - 97 ,col - 97,-1,0); 
        valid = true;
    }
    if(checkLegalInDirection(board, n, row - 97, col - 97, colour, 0, 1)) {
        flipTiles(board, colour, row - 97 ,col - 97,0,1); 
        valid = true;
    }
    if(checkLegalInDirection(board, n, row - 97, col - 97, colour, 0, -1)) {
        flipTiles(board, colour, row - 97 ,col - 97,0,-1); 
        valid = true;
    }
    
    if(checkLegalInDirection(board, n, row - 97, col - 97, colour, -1, -1)) {
        flipTiles(board, colour, row - 97 ,col - 97,-1,-1); 
        valid = true;
    }
    if(checkLegalInDirection(board, n, row - 97, col - 97, colour, 1, 1)) {
        flipTiles(board, colour, row - 97 ,col - 97,1,1); 
        valid = true;
    }
    if(checkLegalInDirection(board, n, row - 97, col - 97, colour, 1, -1)) {
        flipTiles(board, colour, row - 97 ,col - 97,1,-1); 
        valid = true;
    }
    if(checkLegalInDirection(board, n, row - 97, col - 97, colour, -1, 1)) {
        flipTiles(board, colour, row - 97 ,col - 97,-1,1); 
        valid = true;
    }
    
    board[row-97][col-97] = colour;
    
    if(valid) printf("Valid Move.\n");
    else printf("Invalid Move.\n");
    
    printBoard(board,n);
    
    return 0;
}

int getSize(int n){
    
    //gets board size
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    
    return n;   
}

char initializeBoard(char board[MAX][MAX], int n){

    //initializes the U array 
    for(int i = 0; i<n; i++){
        for(int j = 0;j<n; j++){
            board[i][j] = 'U';
            if(((i+1 == n/2) && (j+1 == n/2)) || ((i+1 == n/2+1) && (j+1 == n/2 + 1))) board[i][j] = 'W';
            if(((i+1 == n/2) && (j+1 == n/2+1)) || ((i+1 == n/2+1) && (j+1 == n/2))) board[i][j] = 'B';
        }
    }
    return board[MAX][MAX];
}

char boardConfig(char board[MAX][MAX]){
    
    //sets the initial board configuration
    char colour, row, col;
    bool cont = true;
    printf("Enter board configuration: \n");
    while(cont){
        scanf(" %c%c%c", &colour, &row, &col);
        int i = row-97;int j = col-97;
        board[i][j] = colour;
        if (colour == '!' && i == -64 && j == -64) cont = false;
    }
    return board[MAX][MAX];
    
}

char printBoard(char board[MAX][MAX], int n){

    //prints the first row 
    printf("  ");
    for(int i = 0;i<n;i++){
        printf("%c", 'a' + i);
    }
    printf("\n");
    
    //prints the board array and the first column
    for(int i = 0; i < n; i++){
        printf("%c ", 'a' + i);
        for(int j = 0;j <n;j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}

bool positionInBounds(int n, int row, int col){
    if (row > n-1 || col > n -1 || row < 0 || col < 0) {
        return false;
    } else {
//        printf("true");
        return true;

    }
}

bool checkLegalInDirection(char board[MAX][MAX], int n, int row, int col, char colour, int deltaRow, int deltaCol){    
    
    //checking if the position has already been played (invalid)
    if (board[row][col] !='U')  return false;
    
    
    //checking if adjacent one is the same colour (invalid)
    if(board[row+deltaRow][col+deltaCol] == colour) return false;
    
    
    //checking if adjacent one is empty (invalid)
    if(board[row+deltaRow][col+deltaCol] == 'U') return false;
    
    //checking if out of bounds (invalid)
    if(!positionInBounds(n,row+deltaRow,col+deltaCol)) return false;
        
    //checking if there is eventually an existing colour as the one being played down the line (valid)
    while(positionInBounds(n,row + deltaRow,col + deltaCol) && board[row + deltaRow][col + deltaCol] != colour){         //checks to see if within board
        
        if(deltaRow!=0){
            if(deltaRow<0) deltaRow--;
            else deltaRow++;
        }
        
        if(deltaCol!=0){
            if(deltaCol<0) deltaCol--;
            else deltaCol++;
        }
        
        if(board[row + deltaRow][col + deltaCol] == colour){        //aligns with the correct colour
            return true;                                
        }
        if (board[row + deltaRow][col + deltaCol] == 'U'){          //not a capture
            return false;                               
        }
    }
    return false;
}

void flipTiles(char board[MAX][MAX], char colour, int row, int col, int deltaRow, int deltaCol){
    
    while(board[row+deltaRow][col+deltaCol] != colour){
        
        board[row+deltaRow][col+deltaCol] = colour;
                
        if(deltaRow!=0){
            if(deltaRow<0) deltaRow--;
            else deltaRow++;
        }
        
        if(deltaCol!=0){
            if(deltaCol<0) deltaCol--;
            else deltaCol++;
        }
    }
}