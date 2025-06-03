/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // Default result when target is not found
        vector<int> notFound = {-1, -1};

        // Edge case: empty array
        if (nums.empty())
            return notFound;

        // Use lower_bound to find the first position >= target
        auto lowerIt = lower_bound(nums.begin(), nums.end(), target);

        // Check if target is actually present in the array
        if (lowerIt == nums.end() || *lowerIt != target)
            return notFound;

        // Get index of the first occurrence
        int firstIndex = lowerIt - nums.begin();
        int left = firstIndex;
        int right = firstIndex;

        // Move left to find the actual starting position
        while (left > 0 && nums[left - 1] == target)
            left--;

        // Move right to find the actual ending position
        while (right < nums.size() - 1 && nums[right + 1] == target)
            right++;

        // Return the range
        return {left, right};
    }
};
