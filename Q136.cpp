//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = sum ^ nums[i];
        }
        return sum;
    
    }
};