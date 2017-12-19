//
// Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/
//
// Given a m x n matrix, if an element is 0, set its entire row 
// and column to 0. Do it in place.
//

#include <iostream>
#include <vector>


void set_zeroes(std::vector<std::vector<int>>& matrix) {        
    int nrows = matrix.size(), ncols = matrix[0].size();
    int first_col_has_0 = false;

    // Go thru each row
    for (int i = 0; i < nrows; i++) {
        // If first element in row is 0, ...
        if (matrix[i][0] == 0)
            first_col_has_0 = true;

        // Go thru other columns (elements) searching for 0
        // If found, mark first element of that row AND column with 0

        for (int j = 1; j < ncols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }


    // Matrix now has 0's in first element of each row/col to be changed
    // Change cell to 0 if it's row OR col are supposed to be all 0

    for (int i = nrows - 1; i >= 0; i--) {
        for (int j = ncols - 1; j >= 1; j--) 
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

        if (first_col_has_0) 
            matrix[i][0] = 0;
    }
}




// Print utility
void print_matrix(std::vector<std::vector<int>> & matrix) {

    for (const auto & row: matrix) {
        for (const auto & element: row) 
            std::cout << element << ' ';
        std::cout << std::endl;
    }
}

// Demonstration
int main() {

    std::vector<std::vector<int>> matrix{
        {3,5,5,6,9,1,4,5,0,5},
        {2,7,9,5,9,5,4,9,6,8},
        {6,0,7,8,1,0,1,6,8,1},
        {7,2,6,5,8,5,6,5,0,6},
        {2,3,3,1,0,4,6,5,3,5},
        {5,9,7,3,8,8,5,1,4,3},
        {2,4,7,9,9,8,4,7,3,7},
        {3,5,2,8,8,2,2,4,9,8}
    };

    std::cout << "Input Matrix:\n";
    print_matrix(matrix);
    std::cout << "\nFixed w/ Zeroes:\n";
    set_zeroes(matrix);
    print_matrix(matrix);
}
