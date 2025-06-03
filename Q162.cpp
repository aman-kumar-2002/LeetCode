/*A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words,
an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // If the input array is empty, no peak exists
        if (nums.empty())
        {
            return -1;
        }

        // If there's only one element, it's the peak by default
        if (nums.size() == 1)
        {
            return 0;
        }

        // Iterate through the array (except the last element)
        for (int currentIndex = 0; currentIndex < nums.size() - 1; currentIndex++)
        {
            // If the current element is greater than the next element,
            // then currentIndex is a peak
            if (nums[currentIndex] > nums[currentIndex + 1])
            {
                return currentIndex;
            }
        }

        // If no peak found in the loop, the last element is a peak
        return nums.size() - 1;
    }
};
