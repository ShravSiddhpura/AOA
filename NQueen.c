#include<stdio.h>
#include<stdbool.h>

#define  n 4

void print(int board[n][n]){
    for(int i=0 ;  i<n ; i++){
        for(int j=0 ; j<n ; j++){
            printf("%d" , board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[n][n], int row , int col){
    int i,j;

    //coln above current row
    for(i=0 ; i<row ; i++){
        if(board[i][col]){
            return false;
        }
    }
    
    //upper left diagonal 
    for(i=row-1 , j = col-1 ; i>=0 && j>=0 ; i-- , j--){
        if(board[i][j]){
            return false;
        }
    }

    //upper right diagonal
    for(i=row-1 , j = col+1 ;i>=0 && j<n ; i-- , j++){
        if(board[i][j]){
            return false;
        }
    }

    return true;
}

bool solveNQueen(int board[n][n] , int row){
    //base case
    if(row >= n ){
        return true;
    }

    //placing queen
    for(int col = 0 ; col < n ; col++){
        //if safe:
        if(isSafe(board,row,col)){
            board[row][col]= 1 ;
        
            if(solveNQueen(board , row+1)){
                    return true;
            }
        }
        board[row][col] = 0;
    }
    return false;
}

void solveNQ(){
    int board[n][n] = {0};
    if(solveNQueen(board , 0) == false){
        printf("Soln does not exist \n");
        return;
    }

    print(board);
}

int main() {
    solveNQ();
    return 0;
}