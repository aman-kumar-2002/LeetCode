/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n; // Handle cases where k > n

        // Reverse the entire vector
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};
