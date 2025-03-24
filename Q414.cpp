/*Given an integer array nums, return the third distinct maximum number in this array.
If the third maximum does not exist, return the maximum number.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if (nums.size() >= 3)
        {
            return nums[nums.size() - 3];
        }

        return nums[nums.size() - 1];
    }
};