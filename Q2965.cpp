/*You are given a 0-indexed 2D integer matrix grid of size n * n with values
in the range [1, n2]. Each integer appears exactly once except a which appears twice
and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
*/
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        // To store the result [repeatedValue, missingValue]
        vector<int> result;

        // A set to keep track of seen numbers
        unordered_set<int> seenNumbers;

        // Get the size of the grid (n x n)
        int n = grid.size();

        // Variables for repeated and missing values
        int repeatedValue = -1, missingValue = -1;

        // Initialize the expected sum of all numbers from 1 to n^2
        int expectedSum = (n * n) * (n * n + 1) / 2;
        int actualSum = 0;

        // Traverse the grid to calculate the actualSum and find the repeated value
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int currentValue = grid[i][j];
                actualSum += currentValue;

                // Check if the number has already been seen (repeated)
                if (seenNumbers.find(currentValue) != seenNumbers.end())
                {
                    repeatedValue = currentValue; // Store the repeated value
                }

                // Mark the number as seen
                seenNumbers.insert(currentValue);
            }
        }

        // Calculate the missing value using the formula:
        // missingValue = expectedSum - actualSum + repeatedValue
        missingValue = expectedSum - actualSum + repeatedValue;

        // Add both the repeated and missing values to the result
        result.push_back(repeatedValue);
        result.push_back(missingValue);

        return result; // Return the result containing [repeated, missing]
    }
};
