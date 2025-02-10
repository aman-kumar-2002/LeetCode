/*Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();                 // Total number of elements in the array
        int expectedSum = (n * (n + 1)) / 2; // Sum of first n natural numbers
        int actualSum = 0;                   // Sum of elements present in the array

        // Calculate the sum of elements in the given array
        for (int num : nums)
        {
            actualSum += num;
        }

        // The missing number is the difference between expected and actual sum
        return expectedSum - actualSum;
    }
};
