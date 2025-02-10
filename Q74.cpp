/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity*/

#include <vector>
using namespace std;

class Solution
{
public:
    // Helper function to search for the target in a specific row using binary search
    bool searchInRow(vector<vector<int>> &matrix, int target, int row)
    {
        int numCols = matrix[0].size(); // Number of columns in the matrix
        int start = 0, end = numCols - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (target == matrix[row][mid])
            {
                return true; // Target found in the row
            }
            else if (target > matrix[row][mid])
            {
                start = mid + 1; // Search in the right half
            }
            else
            {
                end = mid - 1; // Search in the left half
            }
        }
        return false; // Target not found in the row
    }

    // Main function to search for a target in the 2D matrix
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int numRows = matrix.size();    // Number of rows in the matrix
        int numCols = matrix[0].size(); // Number of columns in the matrix

        int startRow = 0, endRow = numRows - 1;

        // Perform binary search on rows to identify the potential row where the target might exist
        while (startRow <= endRow)
        {
            int midRow = startRow + (endRow - startRow) / 2;

            // Check if the target lies in the range of the current row
            if (target >= matrix[midRow][0] && target <= matrix[midRow][numCols - 1])
            {
                return searchInRow(matrix, target, midRow); // Search for the target in the identified row
            }
            else if (target > matrix[midRow][numCols - 1])
            {
                startRow = midRow + 1; // Search in rows below
            }
            else
            {
                endRow = midRow - 1; // Search in rows above
            }
        }

        return false; // Target not found in the matrix
    }
};
