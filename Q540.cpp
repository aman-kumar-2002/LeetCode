/*You are given a sorted array consisting of only integers
where every element appears exactly twice,
except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // Boundary checks for first and last element
            if (mid == 0 && nums[0] != nums[1]) {
                return nums[mid]; // unique element is at the beginning
            }
            if (mid == nums.size() - 1 && nums[nums.size() - 1] != nums[nums.size() - 2]) {
                return nums[mid]; // unique element is at the end
            }

            // Check if the element is the unique one
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Binary search logic
            if (mid % 2 == 0) {  // Even index
                if (nums[mid] == nums[mid + 1]) {
                    st = mid + 2;  // The unique element is in the right half
                } else {
                    end = mid - 1;  // The unique element is in the left half
                }
            } else {  // Odd index
                if (nums[mid] == nums[mid - 1]) {
                    st = mid + 1;  // The unique element is in the right half
                } else {
                    end = mid - 1;  // The unique element is in the left half
                }
            }
        }

        // When st == end, it points to the unique element
        return nums[st];
    }
};
