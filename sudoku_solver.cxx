//
//  Sudoku Solver
//  https://leetcode.com/problems/sudoku-solver/
//
//  Solve a sudoku puzzle. Assume one unique solution exists. Empty cells
//  are denoted by '.'
//
//  Joel Rorseth
//  Created on September 3, 2017
//

#include <iostream>
#include <vector>

// Determine if 'val' can be placed at board[i][j]
// Its makes sure that 'val' is not already in this row, col or local diagonal
bool check(std::vector<std::vector<char>> & board, int i, int j, char val) {
    
    int row = i - i%3;
    int column = j - j%3;
    
    // Check all numbers in column j
    for (int x=0; x<9; ++x) if (board[x][j] == val) return false;
    
    // Check all numbers in row i
    for (int y=0; y<9; ++y) if (board[i][y] == val) return false;
    
    // Check diagonal numbers in the local square
    for (int x=0; x<3; ++x)
        for (int y=0; y<3; ++y)
            if (board[row+x][column+y] == val) return false;
    
    return true;
}


// Recursively solve row by row, attempting to solve for each spot left to right
bool solve_recursive(std::vector<std::vector<char>> & board, int i, int j) {
    
    // Base case: If last row finished, algorithm is done
    if (i == 9) return true;
    
    // Base Case: If done this row, move to start of next row
    if (j == 9) return solve_recursive(board, i+1, 0);
    if (board[i][j] != '.') return solve_recursive(board, i, j+1);
    
    // Check if any number 1-9 can be placed at board[i][j]
    for (char c = '1'; c <= '9'; ++c)
        if (check(board, i, j, c)) {
            
            // If it can, place it and attempt to solve for board[i][j+1]
            board[i][j] = c;
            
            if (solve_recursive(board, i, j+1))
                return true;
            
            // No match, keep empty placeholder here
            board[i][j] = '.';
        }
    
    return false;
}


void solve_sudoku(std::vector<std::vector<char>> & board) {
    solve_recursive(board, 0, 0);
}


void print_sudoku(std::vector<std::vector<char>> & board) {

    for (int i=0; i < board.size(); ++i) {
        if (!(i%3)) std::cout << '\n';
        
        for (int j=0; j < board[i].size(); ++j) {
            
            if (!(j%3)) std::cout << ' ';
            std::cout << board[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

// Demonstration
int main() {
 
    std::vector<std::vector<char>> board{
        {'8','6','.','.','2','.','.','.','.'},
        {'.','.','.','7','.','.','.','5','9'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','6','.','8','.','.'},
        {'.','4','.','.','.','.','.','.','.'},
        {'.','.','5','3','.','.','.','.','7'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','2','.','.','.','.','6','.','.'},
        {'.','.','7','5','.','9','.','.','.'}
    };

    std::cout << "Sudoku to Solve: \n";
    print_sudoku(board);

    solve_sudoku(board);
    std::cout << "\nSolved: \n";
    print_sudoku(board);
}
