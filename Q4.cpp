/*Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).*/

#include <vector>
using namespace std;

class Solution
{
public:
    // Function to merge two sorted arrays
    vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {
        int size1 = arr1.size();
        int size2 = arr2.size();

        vector<int> mergedArray;    // To store the merged result
        int index1 = 0, index2 = 0; // Pointers for arr1 and arr2

        // Merge both arrays while comparing elements
        while (index1 < size1 && index2 < size2)
        {
            if (arr1[index1] < arr2[index2])
            {
                mergedArray.push_back(arr1[index1]);
                index1++;
            }
            else
            {
                mergedArray.push_back(arr2[index2]);
                index2++;
            }
        }

        // Add remaining elements from arr1, if any
        while (index1 < size1)
        {
            mergedArray.push_back(arr1[index1]);
            index1++;
        }

        // Add remaining elements from arr2, if any
        while (index2 < size2)
        {
            mergedArray.push_back(arr2[index2]);
            index2++;
        }

        return mergedArray;
    }

    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Merge both arrays into a single sorted array
        vector<int> mergedArray = mergeSortedArrays(nums1, nums2);
        int totalSize = mergedArray.size();

        // Check if the merged array has even or odd length
        if (totalSize % 2 == 0)
        {
            int mid = totalSize / 2;
            int midElement1 = mergedArray[mid];
            int midElement2 = mergedArray[mid - 1];

            // Calculate the average of the two middle elements
            double median = (midElement1 + midElement2) / 2.0;
            return median;
        }

        // If odd, return the middle element
        double median = mergedArray[totalSize / 2];
        return median;
    }
};
