/*Given an integer array nums, find the
subarray
 with the largest sum, and return its sum.
 */

#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr_Sum = 0, Max_sum = INT8_MIN;

        for (int val : nums)
        {

            curr_Sum += val;
            Max_sum = max(curr_Sum, Max_sum);

            if (curr_Sum < 0)
                curr_Sum = 0;
        }
        return (Max_sum);
    }
};