/*Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Helper function to generate all permutations using backtracking
    void generatePermutations(vector<int> &nums, int currentIndex, vector<vector<int>> &allPermutations)
    {
        // Base case: if all elements are fixed, store the permutation
        if (currentIndex == nums.size())
        {
            allPermutations.push_back(nums);
            return;
        }

        // Iterate through possible swaps for the current position
        for (int i = currentIndex; i < nums.size(); i++)
        {
            swap(nums[currentIndex], nums[i]);                             // Swap current element with index i
            generatePermutations(nums, currentIndex + 1, allPermutations); // Recur for next index
            swap(nums[currentIndex], nums[i]);                             // Backtrack to restore original state
        }
    }

    // Function to return all permutations of the given array
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> allPermutations; // Stores all generated permutations
        generatePermutations(nums, 0, allPermutations);
        return allPermutations;
    }
};
