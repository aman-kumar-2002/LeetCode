/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        // Sort the array to use the two-pointer approach
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            // Skip duplicate elements for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i]; // We want two numbers that sum to -nums[i]
            int left = i + 1, right = n - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second element
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Skip duplicates for the third element
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // Move both pointers
                    left++;
                    right--;
                }
                else if (sum < target)
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

        return ans;
    }
};
