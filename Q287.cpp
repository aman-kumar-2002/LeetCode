/*Given an array of integers nums containing n + 1 integers
where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.
*/

#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // Initialize two pointers: slow and fast, both starting at the first element
        int slow = nums[0], fast = nums[0];

        // Phase 1: Detect the cycle using the Floyd's Tortoise and Hare algorithm
        do
        {
            slow = nums[slow];       // Move slow pointer one step
            fast = nums[nums[fast]]; // Move fast pointer two steps
        } while (slow != fast); // Continue until they meet inside the cycle

        // Phase 2: Find the entry point of the cycle
        slow = nums[0]; // Move slow pointer back to the start of the array

        while (slow != fast)
        {
            slow = nums[slow]; // Move both slow and fast pointers one step at a time
            fast = nums[fast];
        }

        // Both pointers meet at the starting point of the cycle (duplicate number)
        return slow;
    }
};
