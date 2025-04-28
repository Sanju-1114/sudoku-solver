#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char dig,
            vector<vector<bool>> &rowVisited,
            vector<vector<bool>> &colVisited,
            vector<vector<bool>> &boxVisited) {
    int boxIndex = (row / 3) * 3 + (col / 3);

    // Check if digit already exists in row, column, or 3x3 box
    if (rowVisited[row][dig - '1'] || colVisited[col][dig - '1'] || boxVisited[boxIndex][dig - '1']) {
        return false;
    }

    return true;
}

bool helper(vector<vector<char>> &board, int row, int col,
            vector<vector<bool>> &rowVisited,
            vector<vector<bool>> &colVisited,
            vector<vector<bool>> &boxVisited) {
    if (row == 9) {
        return true; // Sudoku solved
    }

    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == 9) { // Move to the next row
        nextRow++;
        nextCol = 0;
    }

    if (board[row][col] != '.') { // Skip pre-filled cells
        return helper(board, nextRow, nextCol, rowVisited, colVisited, boxVisited);
    }

    for (char dig = '1'; dig <= '9'; dig++) {
        if (isSafe(board, row, col, dig, rowVisited, colVisited, boxVisited)) {
            int boxIndex = (row / 3) * 3 + (col / 3);
            // Mark digit as visited
            rowVisited[row][dig - '1'] = true;
            colVisited[col][dig - '1'] = true;
            boxVisited[boxIndex][dig - '1'] = true;

            board[row][col] = dig;

            if (helper(board, nextRow, nextCol, rowVisited, colVisited, boxVisited)) {
                return true;
            }

            // Backtrack
            board[row][col] = '.';
            rowVisited[row][dig - '1'] = false;
            colVisited[col][dig - '1'] = false;
            boxVisited[boxIndex][dig - '1'] = false;
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>> &board) {
    vector<vector<bool>> rowVisited(9, vector<bool>(9, false));
    vector<vector<bool>> colVisited(9, vector<bool>(9, false));
    vector<vector<bool>> boxVisited(9, vector<bool>(9, false));

    // Initialize visited arrays based on the initial board state
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int dig = board[i][j] - '1';
                int boxIndex = (i / 3) * 3 + (j / 3);
                rowVisited[i][dig] = true;
                colVisited[j][dig] = true;
                boxVisited[boxIndex][dig] = true;
            }
        }
    }

    helper(board, 0, 0, rowVisited, colVisited, boxVisited);
}

int main() {
    vector<vector<char>> board = {
        {'8', '2', '7', '1', '5', '4', '3', '9', '6'},
        {'9', '.', '3', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '8', '.', '.', '.', '6', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '6', '.', '.', '3', '.', '5', '1', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '4'},
        {'.', '.', '.', '.', '.', '6', '2', '8', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '3', '.'},
        {'.', '.', '1', '9', '.', '5', '.', '.', '7'}};

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