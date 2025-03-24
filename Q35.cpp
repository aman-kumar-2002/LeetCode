/*Given a sorted array of distinct integers and a target value, return
the index if the target is found. If not, return the index where
it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.*/

#include <vector>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;                // Start of the search range
        int right = nums.size() - 1; // End of the search range

        while (left <= right)
        {
            int mid = left + (right - left) / 2; // Calculate the middle index

            if (nums[mid] == target)
            {               // If the target is found
                return mid; // Return the index
            }

            if (target < nums[mid])
            { // Search in the left half
                right = mid - 1;
            }
            else
            { // Search in the right half
                left = mid + 1;
            }
        }

        return left; // Position where the target should be inserted
    }
};
