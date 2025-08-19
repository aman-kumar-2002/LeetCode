/*
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include <vector>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int n = nums.size();
        long long totalSubarrays = 0; // final answer

        int startIndex = 0; // start of a zero block
        int endIndex = 0;   // end of a zero block

        // Scan through the array
        while (startIndex < n)
        {
            if (nums[startIndex] == 0)
            {
                // Find the full length of consecutive zeros
                endIndex = startIndex;
                while (endIndex < n && nums[endIndex] == 0)
                {
                    endIndex++;
                }

                // Length of this zero block
                long long blockLength = endIndex - startIndex;

                // Number of subarrays in a block of length k is k*(k+1)/2
                totalSubarrays += (blockLength * (blockLength + 1LL)) / 2;

                // Move startIndex past this block
                startIndex = endIndex;
            }
            else
            {
                // Skip non-zero elements
                startIndex++;
            }
        }

        return totalSubarrays;
    }
};
