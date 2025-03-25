/*You have a set of integers s, which originally contains all the numbers from 1 to n.
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set,
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        // Sort the array to easily identify duplicates and missing numbers
        sort(nums.begin(), nums.end());

        vector<int> result; // To store [duplicate, missing]
        int size = nums.size();
        int missingNumber = -1, duplicateNumber = -1;

        for (int i = 0; i < size; i++)
        {
            // Identify the duplicate number
            if (i > 0 && nums[i] == nums[i - 1])
            {
                duplicateNumber = nums[i];
            }

            // Identify the missing number
            if ((i > 0 && nums[i] > nums[i - 1] + 1) || (i == 0 && nums[i] != 1))
            {
                missingNumber = (i == 0) ? 1 : nums[i - 1] + 1;
            }
        }

        // Handle the case where the missing number is at the end of the array
        if (missingNumber == -1)
        {
            missingNumber = size;
        }

        // Store the duplicate and missing numbers in the result vector
        result.push_back(duplicateNumber);
        result.push_back(missingNumber);

        return result;
    }
};
