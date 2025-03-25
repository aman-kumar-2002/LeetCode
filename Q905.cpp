/*Given an integer array nums, move all the even integers at the beginning
of the array followed by all the odd integers.

Return any array that satisfies this condition.*/

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> evenNums; // Vector to store even numbers
        vector<int> oddNums;  // Vector to store odd numbers

        // Separate even and odd numbers
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                evenNums.push_back(nums[i]); // Add even numbers to `evenNums`
            }
            else
            {
                oddNums.push_back(nums[i]); // Add odd numbers to `oddNums`
            }
        }

        // Append all odd numbers to the end of even numbers
        evenNums.insert(evenNums.end(), oddNums.begin(), oddNums.end());

        return evenNums; // Return the sorted vector
    }
};
