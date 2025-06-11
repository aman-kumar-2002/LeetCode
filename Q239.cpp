/*
You are given an array of integers nums, there is a sliding window of size k
which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> windowIndices; // Stores indices of potential max elements
        vector<int> result;

        // Process the first k elements
        for (int i = 0; i < k; i++)
        {
            while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i])
            {
                windowIndices.pop_back();
            }
            windowIndices.push_back(i);
        }

        // Process the rest of the array
        for (int i = k; i < nums.size(); i++)
        {
            result.push_back(nums[windowIndices.front()]); // Add max of previous window

            // Remove elements out of current window
            while (!windowIndices.empty() && windowIndices.front() <= i - k)
            {
                windowIndices.pop_front();
            }

            // Maintain decreasing order in deque
            while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i])
            {
                windowIndices.pop_back();
            }

            windowIndices.push_back(i);
        }

        // Add max for the last window
        result.push_back(nums[windowIndices.front()]);
        return result;
    }
};
