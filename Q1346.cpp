/*Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]

*/

#include <vector>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &nums)
    {

        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++)
        {

            // Compare the current element with every other element
            for (int j = 0; j < nums.size(); j++)
            {

                // Ensure the same element is not compared to itself
                if (i != j && nums[i] == 2 * nums[j])
                {
                    return true; // Found a valid pair
                }
            }
        }
        return false; // No valid pair found
    }
};
