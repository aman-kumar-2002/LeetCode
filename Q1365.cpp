/*Given the array nums, for each nums[i] find out how many numbers
in the array are smaller than it. That is, for each nums[i]
you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.*/

#include <vector>
#include <algorithm> // For sort
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {

        // Create a copy of the original array to sort
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> result; // Store the final result
        int size = nums.size();

        // Iterate through the original array
        for (int i = 0; i < size; i++)
        {
            int currentNum = nums[i];
            int count = 0; // Count how many numbers are smaller

            // Count smaller numbers in the sorted array
            for (int j = 0; j < size; j++)
            {
                if (sortedNums[j] < currentNum)
                {
                    count++;
                }
                else
                {
                    break; // No need to check further as the array is sorted
                }
            }

            result.push_back(count); // Store the count for the current number
        }

        return result; // Return the final result
    }
};
