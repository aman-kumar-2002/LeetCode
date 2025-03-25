/*Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> result;    // Stores the final sorted result
        vector<int> leftovers; // Stores elements not present in `arr2`

        // Step 1: Add elements from `arr2` in order, including duplicates
        for (int i = 0; i < arr2.size(); i++)
        {
            int targetElement = arr2[i]; // Current element from `arr2`

            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr1[j] == targetElement)
                { // Match found
                    result.push_back(targetElement);
                }
            }
        }

        // Step 2: Collect elements from `arr1` that are not in `arr2`
        for (int i = 0; i < arr1.size(); i++)
        {
            bool isInArr2 = false;

            for (int j = 0; j < arr2.size(); j++)
            {
                if (arr1[i] == arr2[j])
                { // If element is found in `arr2`
                    isInArr2 = true;
                    break;
                }
            }

            if (!isInArr2)
            { // If not found in `arr2`, add to leftovers
                leftovers.push_back(arr1[i]);
            }
        }

        // Step 3: Sort the leftover elements in ascending order
        sort(leftovers.begin(), leftovers.end());

        // Step 4: Append sorted leftover elements to the result
        result.insert(result.end(), leftovers.begin(), leftovers.end());

        return result; // Return the final sorted result
    }
};
