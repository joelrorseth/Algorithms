//
//  Island Perimeter
//  https://leetcode.com/problems/island-perimeter/
//  
//  Given an insland, represented as a matrix of integers where 1
//  represents land and 0 represents water, determine the perimeter
//  of the island itself. Assume all area outside of given island is
//  water, there are no lakes (no water isolated in land), and land
//  cannot be connected diagonally (only vertically / horizontally).
//
//  Joel Rorseth
//  Created on May 25, 2017
//

#include <iostream>
#include <vector>

// Solution
int island_perimeter(std::vector<std::vector<int>> & grid) {
    int land_count = 0, repeat = 0;

    // Loop through each square (row by column)
    for (int i = 0; i < grid.size(); i++)           // Rows
        for (int j = 0; j < grid[i].size(); j++)    // Columns

            // If land
            if (grid[i][j] == 1) {
                ++land_count;

                // Count occurences of land above or to the left
                // Prevent accessing grid[negative indexes][""]

                if (i!=0 && grid[i-1][j] == 1) ++repeat;
                if (j!=0 && grid[i][j-1] == 1) ++repeat;
            }

    // Total land walls - (2 * Number of times lands were adjacent) 
    // Needs * 2 because for each wall on wall, there is still two
    // walls there, and was counted as such in 'Total land walls'

    return 4 * land_count - repeat * 2;
}

// Matrix display function
void print_island(std::vector<std::vector<int>> & grid) {

    for (auto row: grid) {
        for (auto element: row) 
            std::cout << element << ' ';
        std::cout << '\n';
    }
}

// Demonstration
int main() {

    std::vector<std::vector<int>> island{
        {0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
    
    std::cout << "Island:\t\tLand=1, Water=0\n";
    print_island(island);

    std::cout << "The perimeter of the island is " 
        << island_perimeter(island) << std::endl;
}
