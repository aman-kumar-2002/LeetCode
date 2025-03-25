/*Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].
You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.*/

#include <vector>
#include <algorithm> // For sort()
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());

        // Flip the smallest negative numbers first
        for (int i = 0; i < nums.size() && k > 0; i++)
        {
            if (nums[i] < 0)
            {
                nums[i] = -nums[i]; // Flip the negative number
                k--;
            }
        }

        // If k is still odd, flip the smallest element
        if (k % 2 == 1)
        {
            // Sort again to find the smallest element
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0]; // Flip the smallest element
        }

        // Calculate the total sum of the array
        int totalSum = 0;
        for (int num : nums)
        {
            totalSum += num;
        }

        return totalSum; // Return the largest possible sum
    }
};
