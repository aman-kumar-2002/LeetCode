/*The next greater element of some element x in an array is the first greater element
that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j]
and determine the next greater element of nums2[j] in nums2. If there is no next greater element,
then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nextGreaterMap; // Map from element to its next greater element
        stack<int> monoStack;                   // Monotonic decreasing stack

        // Traverse nums2 from right to left
        for (int index = nums2.size() - 1; index >= 0; index--)
        {
            int currentNum = nums2[index];

            // Remove all elements from stack that are less than or equal to currentNum
            while (!monoStack.empty() && monoStack.top() <= currentNum)
            {
                monoStack.pop();
            }

            // If stack is empty, no greater element to the right
            if (monoStack.empty())
            {
                nextGreaterMap[currentNum] = -1;
            }
            else
            {
                nextGreaterMap[currentNum] = monoStack.top();
            }

            // Push currentNum onto the stack
            monoStack.push(currentNum);
        }

        // Build the result for nums1 using the nextGreaterMap
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++)
        {
            result.push_back(nextGreaterMap[nums1[i]]);
        }

        return result;
    }
};
