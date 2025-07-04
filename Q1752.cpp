/*Given an array nums, return true if the array was originally sorted in non-decreasing order,
then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that
B[i] == A[(i+x) % A.length] for every valid index i.
*/

#include <vector>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int rotationBreaks = 0; // Counts the number of places where the sorted order breaks
        int n = nums.size();

        // Traverse the array and count the number of order breaks
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                rotationBreaks++;
            }
        }

        // Check the circular case: last element vs first element
        if (nums[n - 1] > nums[0])
        {
            rotationBreaks++;
        }

        // If there is more than one break in sorted order, it's not a rotated sorted array
        return rotationBreaks <= 1;
    }
};
