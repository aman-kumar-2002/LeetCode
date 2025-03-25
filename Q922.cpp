/*Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.*/

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        vector<int> evenNumbers;              // Store even numbers
        vector<int> oddNumbers;               // Store odd numbers
        vector<int> sortedArray(nums.size()); // Final sorted array with same size as nums

        // Separate even and odd numbers into different vectors
        for (int num : nums)
        {
            if (num % 2 == 0)
            {
                evenNumbers.push_back(num); // Add even numbers to `evenNumbers`
            }
            else
            {
                oddNumbers.push_back(num); // Add odd numbers to `oddNumbers`
            }
        }

        // Merge even and odd numbers in alternating positions
        int evenPos = 0; // Index for placing even numbers
        int oddPos = 0;  // Index for placing odd numbers

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                sortedArray[i] = evenNumbers[evenPos++]; // Place even numbers at even indices
            }
            else
            {
                sortedArray[i] = oddNumbers[oddPos++]; // Place odd numbers at odd indices
            }
        }

        return sortedArray; // Return the final sorted array
    }
};
