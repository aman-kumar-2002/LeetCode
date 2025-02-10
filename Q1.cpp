/*Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order. */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numIndexMap; // Map to store numbers and their indices
        vector<int> result;                  // Vector to store the result indices

        for (int i = 0; i < nums.size(); i++)
        {
            int currentNum = nums[i];             // Current number in the array
            int complement = target - currentNum; // The number we need to find to sum up to target

            // Check if the complement exists in the map
            if (numIndexMap.find(complement) != numIndexMap.end())
            {
                result.push_back(numIndexMap[complement]); // Add the index of the complement
                result.push_back(i);                       // Add the current index
                break;                                     // We found the pair, no need to continue
            }

            // Store the current number and its index in the map
            numIndexMap[currentNum] = i;
        }

        return result; // Return the result containing the indices of the two numbers
    }
};
