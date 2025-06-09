/*
Given n non-negative integers representing an elevation map
where the width of each bar is 1, compute how much water it can trap after raining.
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution_Better_Approach
{
public:
    int trap(vector<int> &elevationMap)
    {
        int size = elevationMap.size();
        if (size == 0)
            return 0;

        vector<int> maxLeft(size);  // maxLeft[i] stores the maximum height to the left of index i (including i)
        vector<int> maxRight(size); // maxRight[i] stores the maximum height to the right of index i (including i)

        // Compute max height to the left of each index
        maxLeft[0] = elevationMap[0];
        for (int i = 1; i < size; i++)
        {
            maxLeft[i] = max(maxLeft[i - 1], elevationMap[i]);
        }

        // Compute max height to the right of each index
        maxRight[size - 1] = elevationMap[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            maxRight[i] = max(maxRight[i + 1], elevationMap[i]);
        }

        // Calculate the total trapped water
        int totalTrappedWater = 0;
        for (int i = 0; i < size; i++)
        {
            int waterLevel = min(maxLeft[i], maxRight[i]);          // Max water level at current index
            int trappedWaterAtIndex = waterLevel - elevationMap[i]; // Water trapped at current index
            totalTrappedWater += trappedWaterAtIndex;
        }

        return totalTrappedWater;
    }
};

class Solution_Optimal_Approach
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int totalTrappedWater = 0;

        int left = 0;      // Pointer starting from the left end
        int right = n - 1; // Pointer starting from the right end

        int maxLeft = 0;  // Highest bar seen from the left so far
        int maxRight = 0; // Highest bar seen from the right so far

        // Loop until the two pointers meet
        while (left < right)
        {
            // Update the maximum heights on both ends
            maxLeft = max(maxLeft, height[left]);
            maxRight = max(maxRight, height[right]);

            // Water trapped is limited by the shorter side
            if (maxLeft < maxRight)
            {
                totalTrappedWater += maxLeft - height[left];
                left++; // Move left pointer inward
            }
            else
            {
                totalTrappedWater += maxRight - height[right];
                right--; // Move right pointer inward
            }
        }

        return totalTrappedWater;
    }
};
