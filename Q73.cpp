/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        bool firstColHasZero = false;

        // First pass: use first row and first column as markers
        for (int row = 0; row < numRows; row++)
        {
            if (matrix[row][0] == 0)
            {
                firstColHasZero = true; // First column needs to be zeroed later
            }
            for (int col = 1; col < numCols; col++)
            {
                if (matrix[row][col] == 0)
                {
                    matrix[row][0] = 0; // Mark corresponding row
                    matrix[0][col] = 0; // Mark corresponding column
                }
            }
        }

        // Second pass: use the markers to set zeroes (excluding first row and column)
        for (int row = 1; row < numRows; row++)
        {
            for (int col = 1; col < numCols; col++)
            {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        // Third pass: zero out the first row if needed
        if (matrix[0][0] == 0)
        {
            for (int col = 0; col < numCols; col++)
            {
                matrix[0][col] = 0;
            }
        }

        // Zero out the first column if needed
        if (firstColHasZero)
        {
            for (int row = 0; row < numRows; row++)
            {
                matrix[row][0] = 0;
            }
        }
    }
};
