/*Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal
and all the elements on the secondary diagonal that are not part of the primary diagonal.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int primaryDiagonalSum = 0, secondaryDiagonalSum = 0;
        int n = mat.size();
        int row = n - 1, col = 0; // Used for secondary diagonal traversal

        // Calculate the sum of both diagonals
        for (int i = 0; i < n; i++)
        {
            primaryDiagonalSum += mat[i][i];       // Primary diagonal element
            secondaryDiagonalSum += mat[row][col]; // Secondary diagonal element
            row--;
            col++;
        }

        // If the matrix size is odd, subtract the middle element (counted twice)
        if (n % 2 != 0)
        {
            int midIndex = n / 2;
            return primaryDiagonalSum + secondaryDiagonalSum - mat[midIndex][midIndex];
        }

        return primaryDiagonalSum + secondaryDiagonalSum;
    }
};
