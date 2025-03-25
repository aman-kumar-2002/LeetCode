/*Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.*/

#include <vector>
#include <cmath> // For abs() function
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int size = nums.size();

        // Step 1: Replace invalid values (<= 0 or larger than size) with `size + 1`
        for (int i = 0; i < size; i++)
        {
            if (nums[i] <= 0 || nums[i] > size)
            {
                nums[i] = size + 1; // Assign a placeholder value
            }
        }

        // Step 2: Use index marking to mark the presence of elements
        for (int i = 0; i < size; i++)
        {
            int element = abs(nums[i]);

            // Skip placeholder values
            if (element == size + 1)
            {
                continue;
            }

            // Mark the corresponding index as visited (negative marking)
            int index = element - 1;
            if (nums[index] > 0)
            {
                nums[index] = -nums[index];
            }
        }

        // Step 3: Find the first missing positive
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1; // Return the missing positive value
            }
        }

        // If all indices are marked, return `size + 1`
        return size + 1;
    }
};
