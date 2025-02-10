/*Given an array nums of n integers, return an array
of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        // Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            // Skip duplicate elements for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                // Skip duplicate elements for the second element
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1, right = n - 1;
                long long newTarget = (long long)target - nums[i]; // Use long long to avoid overflow
                newTarget -= nums[j];                              // Separate subtraction to avoid overflow

                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum == newTarget)
                    {
                        // Found a valid quadruplet
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third element
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        // Skip duplicates for the fourth element
                        while (left < right && nums[right] == nums[right - 1])
                            right--;

                        // Move both pointers
                        left++;
                        right--;
                    }
                    else if (sum < newTarget)
                    {
                        // We need a larger sum, so move the left pointer
                        left++;
                    }
                    else
                    {
                        // We need a smaller sum, so move the right pointer
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
