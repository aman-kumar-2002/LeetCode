/*Given an array of integers nums and an integer k,
return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        // Create a map to store the frequency of prefix sums
        std::unordered_map<int, int> prefixSumCount;

        // Initialize the map with a prefix sum of 0 that occurs once.
        // This is to handle the case where a subarray from index 0 to i sums to k.
        prefixSumCount[0] = 1;

        // Initialize variables
        int currentPrefixSum = 0; // Tracks the sum of elements from the start to the current index
        int countOfSubarrays = 0; // Tracks the number of subarrays whose sum equals k

        // Iterate through each element in the array
        for (int num : nums)
        {
            // Update the current prefix sum with the current number
            currentPrefixSum += num;

            // Check if there is any previous prefix sum such that
            // currentPrefixSum - previousPrefixSum == k
            if (prefixSumCount.find(currentPrefixSum - k) != prefixSumCount.end())
            {
                // If such a prefix sum exists, it means there is a subarray
                // whose sum is equal to k
                countOfSubarrays += prefixSumCount[currentPrefixSum - k];
            }

            // Update the frequency of the current prefix sum in the map
            prefixSumCount[currentPrefixSum]++;
        }

        // Return the total count of subarrays whose sum equals k
        return countOfSubarrays;
    }
};
