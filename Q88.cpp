/*You are given two integer arrays nums1 and nums2,
sorted in non-decreasing order, and two integers m and n,
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function,
but instead be stored inside the array nums1. To accommodate this,
nums1 has a length of m + n, where the first m elements denote the elements
that should be merged, and the last n elements are set to 0 and should be ignored.
nums2 has a length of n.
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int idx = m + n - 1; // Index for the last position in nums1
        int i = m - 1;       // Last valid element in nums1
        int j = n - 1;       // Last element in nums2

        // Merge nums1 and nums2 in reverse order
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
            {
                nums1[idx--] = nums1[i--];
            }
            else
            {
                nums1[idx--] = nums2[j--];
            }
        }

        // Copy remaining elements from nums2, if any
        while (j >= 0)
        {
            nums1[idx--] = nums2[j--];
        }
    }
};