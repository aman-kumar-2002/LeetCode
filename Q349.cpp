/*Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                i++; // Move forward in nums1
            }
            else if (nums1[i] > nums2[j])
            {
                j++; // Move forward in nums2
            }
            else
            {
                // Add common element only if it's not already added
                if (result.empty() || result.back() != nums1[i])
                {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }

        return result;
    }
};
