/*Given an integer array nums and an integer k,
return true if there are two distinct indices i and j
in the array such that nums[i] == nums[j] and abs(i - j) <= k.*/

#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size(); // Get the size of the array

        for (int i = 0; i < n; ++i)
        {
            // Check all elements within the k range from the current index
            for (int j = i + 1; j < min(i + k + 1, n); ++j)
            {
                if (nums[i] == nums[j])
                {
                    return true; // Duplicate found within range k
                }
            }
        }
        return false; // No duplicates found within range k
    }
};
