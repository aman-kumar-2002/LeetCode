/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.
*/

#include <vector>
using namespace std;

class Solution
{
public:
    // Generates a specific row (1-indexed) of Pascal's Triangle using combinations (nCr)
    vector<int> generateRow(int rowIndex)
    {
        vector<int> row;
        long long currentVal = 1;

        row.push_back(1); // First element is always 1

        // Compute the rest of the elements using formula: C(n, k) = C(n, k-1) * (n - k + 1) / k
        for (int col = 1; col < rowIndex; col++)
        {
            currentVal = currentVal * (rowIndex - col);
            currentVal = currentVal / col;
            row.push_back(static_cast<int>(currentVal)); // Cast to int for compatibility
        }

        return row;
    }

    // Generates the first 'numRows' of Pascal's Triangle
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascalTriangle;

        for (int rowNum = 1; rowNum <= numRows; rowNum++)
        {
            vector<int> row = generateRow(rowNum);
            pascalTriangle.push_back(row);
        }

        return pascalTriangle;
    }
};
