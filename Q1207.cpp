/*Given an array of integers arr,
return true if the number of occurrences of each value in the array is unique or false otherwise.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // Sort the array to group same elements together

        vector<int> freqList; // Store occurrences of each element

        int count = 1; // Initialize count for frequency tracking
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {            // If current element is same as previous
                count++; // Increase the frequency count
            }
            else
            {
                freqList.push_back(count); // Store the frequency of the previous element
                count = 1;                 // Reset count for new element
            }
        }
        freqList.push_back(count); // Add the last element's frequency

        // Check for unique occurrences
        sort(freqList.begin(), freqList.end()); // Sort the frequency list
        for (int i = 1; i < freqList.size(); i++)
        {
            if (freqList[i] == freqList[i - 1])
            { // If any two occurrences are the same
                return false;
            }
        }

        return true; // All occurrences are unique
    }
};
