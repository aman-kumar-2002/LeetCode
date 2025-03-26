/*There are n kids with candies. You are given an integer array candies,
where each candies[i] represents the number of candies the ith kid has,
and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if,
after giving the ith kid all the extraCandies,
they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.*/

#include <vector>
#include <climits> // For INT_MIN
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxCandies = INT_MIN; // To store the maximum candies a kid initially has

        // Step 1: Find the maximum number of candies any kid initially has
        for (int i = 0; i < candies.size(); i++)
        {
            maxCandies = max(maxCandies, candies[i]);
        }

        vector<bool> canHaveMaxCandies; // Result array to store true/false values

        // Step 2: Check if each kid can have the maximum or more candies with extra candies
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= maxCandies)
            {
                canHaveMaxCandies.push_back(true); // Kid can have the most candies
            }
            else
            {
                canHaveMaxCandies.push_back(false); // Kid can't have the most candies
            }
        }

        return canHaveMaxCandies;
    }
};
