/*Given an integer array nums, return an array answer such that answer[i]
is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1); // Initialize answer array with 1s
        
        // Compute prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        
        // Compute suffix products and multiply with prefix products in answer
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--) {
            
            suffix *= nums[i+1];
            answer[i] *= suffix;
        }
        
        return answer;
    }
};
