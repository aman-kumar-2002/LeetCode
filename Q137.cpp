/*Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
        
        // Iterate through each number in the array
        for (int i = 0; i < n; i++) {
            int occurrenceCount = 0; // Variable to count occurrences of the current number
            
            // Check the current number against every other number in the array
            for (int j = 0; j < n; j++) {
                // Increment occurrenceCount if the numbers match, excluding self-comparison
                if (nums[i] == nums[j] && i != j) {
                    occurrenceCount++;
                }
            }
            
            // If the current number has no duplicates, it is the single number
            if (occurrenceCount == 0) {
                return nums[i];
            }
        }
        
        // If no single number is found (should not happen as per problem constraints)
        return 0;
    }
};
