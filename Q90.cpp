/*Given an integer array nums that may contain duplicates, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.*/

#include <vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    // Helper function to generate all unique subsets recursively
    void generateUniqueSubsets(vector<int> &nums, vector<int> &currentSubset, int index, vector<vector<int>> &allSubsets)
    {
        // Store the current subset
        allSubsets.push_back(currentSubset);

        // Iterate over elements starting from index
        for (int i = index; i < nums.size(); i++)
        {
            // Skip duplicates to ensure unique subsets
            if (i > index && nums[i] == nums[i - 1])
            {
                continue;
            }

            // Include current element in the subset
            currentSubset.push_back(nums[i]);
            generateUniqueSubsets(nums, currentSubset, i + 1, allSubsets);
            currentSubset.pop_back(); // Backtrack to explore other subsets
        }
    }

    // Function to return all unique subsets of the given array
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> allSubsets; // Stores all possible unique subsets
        vector<int> currentSubset;      // Temporary subset being formed

        sort(nums.begin(), nums.end()); // Sort to handle duplicates correctly
        generateUniqueSubsets(nums, currentSubset, 0, allSubsets);
        return allSubsets;
    }
};
