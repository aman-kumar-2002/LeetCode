/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of
arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next
lexicographically greater permutation of its integer.

More formally, if all the permutations of the array are sorted in one container
according to their lexicographical order, then the next permutation of that array
is the permutation that follows it in the sorted container. If such arrangement is not possible,
the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
*/

#include <vector>
using namespace std;

void reverse(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        // Swap the elements at 'start' and 'end' indices
        swap(nums[start], nums[end]);
        // Move the pointers towards the center
        start++;
        end--;
    }
}

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int pivot = -1, n = nums.size();

        // Step 1: Find the pivot
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse the entire array
        if (pivot == -1)
        {
            reverse(nums, 0, n - 1); // Use custom reverse function with indices
            return;
        }

        // Step 3: Find the smallest number greater than nums[pivot]
        for (int i = n - 1; i > pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the subarray from pivot + 1 to the end
        reverse(nums, pivot + 1, n - 1); // Use custom reverse function with indices
    }
};