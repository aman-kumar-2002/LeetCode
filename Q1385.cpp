/*Given two integer arrays arr1 and arr2,
and the integer d, return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i]
such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.*/

#include <vector>
#include <cmath> // For abs() function
using namespace std;

class Solution
{
public:
    int findTheDistanceValue(vector<int> &array1, vector<int> &array2, int distance)
    {
        int validCount = 0; // Count of valid distance values

        // Iterate through each element in `array1`
        for (int i = 0; i < array1.size(); i++)
        {
            bool isValid = true; // Flag to track if the current value is valid

            // Compare with each element in `array2`
            for (int j = 0; j < array2.size(); j++)
            {
                int difference = abs(array1[i] - array2[j]);

                // If difference is less than or equal to `distance`, mark as invalid
                if (difference <= distance)
                {
                    isValid = false; // Mark as invalid
                    break;           // Exit inner loop early
                }
            }

            // Increment count if the value is valid
            if (isValid)
            {
                validCount++;
            }
        }

        return validCount;
    }
};
