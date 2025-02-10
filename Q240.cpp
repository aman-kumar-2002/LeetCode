/*Write an efficient algorithm that searches for a value target
in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Get the number of rows and columns
        int rows = matrix.size();    // Number of rows in the matrix
        int cols = matrix[0].size(); // Number of columns in the matrix

        // Start from the top-right corner of the matrix
        int row = 0;
        int col = cols - 1;

        // Loop until we are within the bounds of the matrix
        while (row < rows && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                // If the target is found, return true
                return true;
            }
            else if (matrix[row][col] > target)
            {
                // If the current element is greater than the target, move left
                col--;
            }
            else
            {
                // If the current element is less than the target, move down
                row++;
            }
        }

        // If we exit the loop, the target was not found
        return false;
    }
};
