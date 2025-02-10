/*You are given an integer mountain array arr of length n where
the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int st = 0, end = n - 1;

        while (st < end) { // Use st < end to avoid unnecessary iterations
            int mid = st + (end - st) / 2;

            // Compare mid with its neighbors safely
            if (arr[mid] > arr[mid + 1]) {
                // If mid is greater than the next element, move the end pointer
                end = mid;
            } else {
                // Otherwise, move the start pointer
                st = mid + 1;
            }
        }

        // st and end converge to the peak element
        return st;
    }
};
