/*Given an integer array nums of unique elements, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.*/

#include <vector>
using namespace std;

class Solution
{
public:
    // Helper function to generate all subsets recursively
    void generateSubsets(vector<int> &nums, vector<int> &currentSubset, int index, vector<vector<int>> &allSubsets)
    {
        if (index == nums.size())
        {
            allSubsets.push_back(currentSubset); // Store the current subset
            return;
        }

        // Include the current element in the subset
        currentSubset.push_back(nums[index]);
        generateSubsets(nums, currentSubset, index + 1, allSubsets);

        // Exclude the current element from the subset (backtracking)
        currentSubset.pop_back();
        generateSubsets(nums, currentSubset, index + 1, allSubsets);
    }

    // Function to return all subsets of the given array
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> allSubsets; // Stores all possible subsets
        vector<int> currentSubset;      // Temporary subset being formed

        generateSubsets(nums, currentSubset, 0, allSubsets);
        return allSubsets;
    }
};
