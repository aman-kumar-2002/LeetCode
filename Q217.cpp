/*Given an integer array nums, return true if any value appears
at least twice in the array, and return false if every element is distinct.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // Sort the array

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true; // Duplicate found
            }
        }

        return false; // No duplicates
    }
};
