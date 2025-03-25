/*A school is trying to take an annual photo of all the students.
The students are asked to stand in a single file line in non-decreasing order by height.
Let this ordering be represented by the integer array expected where
expected[i] is the expected height of the ith student in line.

You are given an integer array heights representing the current order
that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

Return the number of indices where heights[i] != expected[i].*/

#include <vector>
#include <algorithm> // For sort()
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int mismatchCount = 0;                 // Count mismatched heights
        vector<int> expectedHeights = heights; // Create a copy of original heights

        // Sort the copied array to get the expected order
        sort(expectedHeights.begin(), expectedHeights.end());

        // Compare the original and sorted arrays
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != expectedHeights[i])
            {
                mismatchCount++; // Increment for mismatched height
            }
        }

        return mismatchCount; // Return the total mismatches
    }
};
