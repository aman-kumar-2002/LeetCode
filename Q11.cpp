/*You are given an integer array height of length n. There are n vertical lines drawn such that
the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container,
 such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0;                             // Maximum area
        int left = 0, right = height.size() - 1; // Two pointers at the ends of the array

        while (left < right)
        {
            int width = right - left;
            int ht = min(height[left], height[right]);
            ans = max(ans, width * ht); // Calculate and update maximum area

            // Move the pointer pointing to the smaller height
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};
