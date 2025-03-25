/*Given an integer array nums, find three numbers whose product
is maximum and return the maximum product.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        // Sort the array to easily access the smallest and largest values
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Maximum product of the three largest numbers
        int maxProductLargest = nums[n - 1] * nums[n - 2] * nums[n - 3];

        // Maximum product of two smallest numbers (which could be negative) and the largest number
        int maxProductWithNegatives = nums[0] * nums[1] * nums[n - 1];

        // Return the maximum of the two products
        return max(maxProductLargest, maxProductWithNegatives);
    }
};
