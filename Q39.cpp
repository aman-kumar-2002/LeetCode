/*Given an array of distinct integers candidates and a target integer target,
return a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency
of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations
that sum up to target is less than 150 combinations for the given input.*/

#include <vector>
using namespace std;

class Solution
{
public:
    void findCombinations(vector<int> &candidates, int index, int target, vector<vector<int>> &result, vector<int> &currentCombination)
    {
        // Base case: If target sum is reached, add the combination to the result
        if (target == 0)
        {
            result.push_back(currentCombination);
            return;
        }

        // If index goes out of bounds or target becomes negative, return
        if (index == candidates.size() || target < 0)
        {
            return;
        }

        // Include the current candidate
        currentCombination.push_back(candidates[index]);
        findCombinations(candidates, index, target - candidates[index], result, currentCombination); // Allow reuse of the same element
        currentCombination.pop_back();                                                               // Backtrack

        // Exclude the current candidate and move to the next
        findCombinations(candidates, index + 1, target, result, currentCombination);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> currentCombination;

        findCombinations(candidates, 0, target, result, currentCombination);

        return result;
    }
};
