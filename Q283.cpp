/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &arr)
    {

        int size = arr.size();
        int zeroCount = 0; // Counter to track the number of zeros

        // Shift non-zero elements to the left
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == 0)
            {
                zeroCount++; // Count the zeros
            }
            else
            {
                arr[i - zeroCount] = arr[i]; // Move non-zero element to the correct position
            }
        }

        // Fill the trailing part with zeros
        for (int j = size - zeroCount; j < size; j++)
        {
            arr[j] = 0;
        }
    }
};
