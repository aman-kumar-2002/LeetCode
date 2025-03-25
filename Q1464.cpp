/*Given the array of integers nums, you will choose two different indices i and j of that array.
Return the maximum value of (nums[i]-1)*(nums[j]-1).*/

#include <vector>
#include <algorithm> // For sort() function
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());

        int size = nums.size();

        // Calculate the maximum product of the two largest elements (minus 1 each)
        int maxProduct = (nums[size - 1] - 1) * (nums[size - 2] - 1);

        return maxProduct;
    }
};
