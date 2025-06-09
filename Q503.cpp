/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
return the next greater number for every element in nums.

The next greater number of a number x is the first greater number
to its traversing-order next in the array, which means you could search circularly
to find its next greater number. If it doesn't exist, return -1 for this number.
*/

#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nextGreater(n, -1); // Result array initialized with -1
        stack<int> indexStack;          // Stack to store indices

        // Traverse the array twice in reverse to simulate circular behavior
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int circularIndex = i % n;

            // Pop elements from stack that are less than or equal to current element
            while (!indexStack.empty() && nums[indexStack.top()] <= nums[circularIndex])
            {
                indexStack.pop();
            }

            // If stack is not empty, top of the stack is the next greater element
            if (!indexStack.empty())
            {
                nextGreater[circularIndex] = nums[indexStack.top()];
            }

            // Push current index onto the stack
            indexStack.push(circularIndex);
        }

        return nextGreater;
    }
};
