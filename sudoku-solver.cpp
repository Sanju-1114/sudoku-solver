// LeetCode problem 37
#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row , int col ,char dig){
    // Check horizontally
    for (int j = 0; j < 9; j++){
        if(board[row][col] == dig){
            return false;
        }
    }

    //Check Vertically
    for (int i = 0; i < 9; i++){
        if(board[i][col] == dig){
            return false;
        }
    }
    
    //Check In the box   srow-> starting row  and scol-> starting col
    int srow = (row/3)*3 , scol = (col/3)*3 ;
    for(int i = srow ; i<= srow+2 ; i++){
        for (int j = scol; j <= scol+2; j++){
            if(board[i][j] == dig){
                return false;
            }
        }
        
    }
   return true; 
}

bool helper(vector<vector<char>> &board, int row , int col ){
    if(row == 9){
        return true;
    }

    int nextRow = row ;
    int nextCol = col+1;
    if (nextCol == 9){ // If the pointer is at last col
        nextRow = row+1;
        nextCol = 0;
    }
    
    // If already any value
    if (board[row][col] != '.'){
        helper(board , nextRow , nextCol);
    }
    
    //Place the digit
    for(char dig= '1' ; dig <= '9' ; dig++){
        if (isSafe(board , row , col , dig)){
            board[row][col] = dig;
            if(helper(board , nextRow , nextCol)){
                return true;
            }
            
            board[row][col] = '.';
        }
        
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board){
        helper(board , 0 , 0);
}

int main(){
   
    // vector<vector<char>> board;
    // Initialize the board (example board)
    // vector<vector<char>> board = {
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    // };
    vector<vector<char>> board = {
        {'8', '2', '7', '1', '5', '4', '3', '9', '6'},
        {'9', '.', '3', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '8', '.', '.', '.', '6', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '6', '.', '.', '3', '.', '5', '1', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '4'},
        {'.', '.', '.', '.', '.', '6', '2', '8', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '3', '.'},
        {'.', '.', '1', '9', '.', '5', '.', '.', '7'}
    };

    
    solveSudoku(board);

    // Print the solved board
    for (const auto &row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }


    return 0;
}