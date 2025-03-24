/*Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must appear as many times as it shows
in both arrays and you may return the result in any order.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end()); // Sort both arrays
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                i++; // Move pointer in nums1
            }
            else if (nums1[i] > nums2[j])
            {
                j++; // Move pointer in nums2
            }
            else
            {
                result.push_back(nums1[i]); // Common element found
                i++;
                j++;
            }
        }
        return result;
    }
};
