/*Given an array of integers nums which is sorted in ascending order,
and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

#include<vector>
using namespace std;

class Solution {
public:
    // Recursive Binary Search function
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2; // Avoids overflow

            if (nums[mid] == target) {
                return mid; // Target found
            } 
            else if (nums[mid] < target) {
                return binarySearch(nums, target, mid + 1, right); // Search right half
            } 
            else {
                return binarySearch(nums, target, left, mid - 1); // Search left half
            }
        }
        return -1; // Target not found
    }

    // Wrapper function to call binarySearch
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};
