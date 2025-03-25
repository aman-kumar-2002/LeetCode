/*Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity
and with the smallest space complexity possible.*/

#include <vector>
using namespace std;

class Solution
{
public:
    // Function to merge two sorted subarrays into a single sorted array
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int leftSize = mid - left + 1; // Size of left subarray
        int rightSize = right - mid;   // Size of right subarray

        // Temporary vectors for the two halves
        vector<int> leftPart(leftSize);
        vector<int> rightPart(rightSize);

        // Copy data to temporary subarrays
        for (int i = 0; i < leftSize; i++)
        {
            leftPart[i] = nums[left + i];
        }
        for (int j = 0; j < rightSize; j++)
        {
            rightPart[j] = nums[mid + 1 + j];
        }

        // Merge the two sorted subarrays
        int i = 0, j = 0, k = left;

        while (i < leftSize && j < rightSize)
        {
            if (leftPart[i] <= rightPart[j])
            {
                nums[k] = leftPart[i];
                i++;
            }
            else
            {
                nums[k] = rightPart[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of leftPart, if any
        while (i < leftSize)
        {
            nums[k] = leftPart[i];
            i++;
            k++;
        }

        // Copy remaining elements of rightPart, if any
        while (j < rightSize)
        {
            nums[k] = rightPart[j];
            j++;
            k++;
        }
    }

    // Recursive Merge Sort function
    void mergeSort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2; // Find the middle point

            // Recursively sort the left and right halves
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);

            // Merge the sorted halves
            merge(nums, left, mid, right);
        }
    }

    // Main function to sort the array using Merge Sort
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums; // Return the sorted array
    }
};
