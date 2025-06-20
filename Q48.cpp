/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size(); // 'n' is the size of the NxN matrix

        // Step 1: Transpose the matrix
        // Swap matrix[i][j] with matrix[j][i] for all i < j
        // This converts rows to columns
        for (int row = 0; row < n - 1; row++)
        {
            for (int col = row + 1; col < n; col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // Step 2: Reverse each row
        // This mirrors the transposed matrix horizontally
        // Final effect is a 90-degree clockwise rotation
        for (int row = 0; row < n; row++)
        {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};
