/*Given an integer array nums sorted in non-decreasing order,
return an array of the squares of each number sorted in non-decreasing order.*/

#include <vector>
#include <algorithm> // For sort()
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // Square each element in the array
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i]; // Square the current element
        }

        // Sort the squared elements in ascending order
        sort(nums.begin(), nums.end());

        return nums; // Return the sorted squared array
    }
};
