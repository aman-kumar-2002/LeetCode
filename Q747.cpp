/*You are given an integer array nums where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as every other number in the array.
If it is, return the index of the largest element, or return -1 otherwise.*/

#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int maxNum = INT_MIN; // Store the largest number

        // Find the maximum number
        for (int i = 0; i < nums.size(); i++)
        {
            maxNum = max(maxNum, nums[i]);
        }

        // Check if all other numbers are at most half of the maximum
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != maxNum && nums[j] * 2 > maxNum)
            {
                return -1; // If any number is more than half of maxNum, return -1
            }
        }

        int maxIndex = 0; // Store the index of the maximum number

        // Find the index of the maximum number
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] == maxNum)
            {
                maxIndex = k; // Store the index of maxNum
                break;
            }
        }
        return maxIndex; // Return the index of the largest number
    }
};
