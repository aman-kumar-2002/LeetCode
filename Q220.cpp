/*You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.*/

#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
    {
        int n = nums.size();

        // Use a set to quickly check for duplicates
        set<int> uniqueNums(nums.begin(), nums.end());

        // If valueDiff is 0 and all elements are unique, no nearby duplicates exist
        if (valueDiff == 0 && n == uniqueNums.size())
        {
            return false;
        }

        // Check pairs of numbers within the given index difference
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < i + 1 + indexDiff; ++j)
            {
                if (j >= n)
                {
                    break;
                }

                // Check if the absolute difference is within the allowed range
                if (abs((long long)nums[i] - nums[j]) <= valueDiff)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
