/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
*/
#include<iostream>
using namespace std;
#include<vector>
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int freq = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (freq == 0)
            {
                ans = nums[i];
            }
            if (ans == nums[i])
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
        return ans;
    }
};