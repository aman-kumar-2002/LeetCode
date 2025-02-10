/*Given an array nums with n objects colored red, white, or blue,
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2
to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int z_count = 0, o_count = 0, t_count = 0;

        // Count the number of 0s, 1s, and 2s
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                z_count++;
            else if (nums[i] == 1)
                o_count++;
            else
                t_count++;
        }

        // Place 0s in the beginning
        for (int j = 0; j < z_count; j++) {
            nums[j] = 0;
        }

        // Place 1s after the 0s
        for (int j = z_count; j < z_count + o_count; j++) {
            nums[j] = 1;
        }

        // Place 2s after the 1s
        for (int j = z_count + o_count; j < n; j++) {
            nums[j] = 2;
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap nums[mid] and nums[low], increment both pointers
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Just move the mid pointer
                mid++;
            } else { // nums[mid] == 2
                // Swap nums[mid] and nums[high], decrement high pointer
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
