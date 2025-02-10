/*Given an m x n matrix, return all elements of the matrix in spiral order.*/

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();    // Number of rows in the matrix
        int cols = matrix[0].size(); // Number of columns in the matrix

        int startRow = 0, startCol = 0;           // Starting row and column
        int endRow = rows - 1, endCol = cols - 1; // Ending row and column

        vector<int> result; // Vector to store the result in spiral order

        while (startRow <= endRow && startCol <= endCol)
        {
            // Traverse from left to right along the top row
            for (int j = startCol; j <= endCol; j++)
            {
                result.push_back(matrix[startRow][j]);
            }
            startRow++; // Move the start row down after traversing the top row

            // Traverse from top to bottom along the right column
            for (int i = startRow; i <= endRow; i++)
            {
                result.push_back(matrix[i][endCol]);
            }
            endCol--; // Move the end column left after traversing the right column

            // Traverse from right to left along the bottom row (if still within bounds)
            if (startRow <= endRow)
            {
                for (int j = endCol; j >= startCol; j--)
                {
                    result.push_back(matrix[endRow][j]);
                }
                endRow--; // Move the end row up after traversing the bottom row
            }

            // Traverse from bottom to top along the left column (if still within bounds)
            if (startCol <= endCol)
            {
                for (int i = endRow; i >= startRow; i--)
                {
                    result.push_back(matrix[i][startCol]);
                }
                startCol++; // Move the start column right after traversing the left column
            }
        }

        return result; // Return the final result in spiral order
    }
};
