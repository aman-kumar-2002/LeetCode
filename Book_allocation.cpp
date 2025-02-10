#include <iostream>
#include <vector>
using namespace std;

// Helper function to check if the allocation is valid
bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages)
{
    int stu = 1; // Start with the first student
    int pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPages)
            return false; // A single book has more pages than allowed

        if (pages + arr[i] > maxAllowedPages)
        {
            // Allocate to the next student
            stu++;
            pages = arr[i];

            if (stu > m)
                return false; // Too many students needed
        }
        else
        {
            pages += arr[i]; // Add pages to the current student
        }
    }

    return true; // Allocation is valid
}

// Function to find the minimum maximum pages
int allocateBooks(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1; // Not enough books for each student

    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxBook = max(maxBook, arr[i]);
    }

    int ans = -1;
    int st = maxBook, end = sum;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1; // Try for a smaller maximum
        }
        else
        {
            st = mid + 1; // Increase the maximum allowed pages
        }
    }

    return ans; // Return the minimum maximum pages
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;
    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}
