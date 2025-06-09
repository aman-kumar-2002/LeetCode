/*
Given an array of integers heights representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle in the histogram.
*/

#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        // Arrays to store the index of the next smaller element to the right and left
        vector<int> nextSmallerRight(n, 0);
        vector<int> nextSmallerLeft(n, 0);
        stack<int> indexStack;

        // Find the next smaller element to the right for each bar
        for (int i = n - 1; i >= 0; i--)
        {
            while (!indexStack.empty() && heights[indexStack.top()] >= heights[i])
            {
                indexStack.pop();
            }
            nextSmallerRight[i] = indexStack.empty() ? n : indexStack.top();
            indexStack.push(i);
        }

        // Clear the stack for reuse
        while (!indexStack.empty())
        {
            indexStack.pop();
        }

        // Find the next smaller element to the left for each bar
        for (int i = 0; i < n; i++)
        {
            while (!indexStack.empty() && heights[indexStack.top()] >= heights[i])
            {
                indexStack.pop();
            }
            nextSmallerLeft[i] = indexStack.empty() ? -1 : indexStack.top();
            indexStack.push(i);
        }

        // Calculate the largest rectangle area
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int width = nextSmallerRight[i] - nextSmallerLeft[i] - 1;
            int currentArea = heights[i] * width;
            maxArea = max(maxArea, currentArea);
        }

        return maxArea;
    }
};
