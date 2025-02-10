#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

// Function to check if it's possible to place C cows with at least minAllowedDist distance
bool isPossible(vector<int> &arr, int N, int C, int minAllowedDist)
{
    int cows = 1; // Place the first cow in the first stall
    int lastStallPos = arr[0];

    for (int i = 1; i < N; i++)
    {
        // Place the next cow only if the distance is >= minAllowedDist
        if (arr[i] - lastStallPos >= minAllowedDist)
        {
            cows++;
            lastStallPos = arr[i];
        }
        // If all cows are placed, return true
        if (cows == C)
        {
            return true;
        }
    }
    return false;
}

// Function to find the largest minimum distance
int getDistance(vector<int> &arr, int N, int C)
{
    // Sort the stall positions
    sort(arr.begin(), arr.end());

    // Define the search space
    int start = 1;                 // Minimum possible distance
    int end = arr[N - 1] - arr[0]; // Maximum possible distance
    int ans = -1;

    // Binary search on the distance
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Midpoint of the current range

        // Check if it's possible to place cows with this minimum distance
        if (isPossible(arr, N, C, mid))
        {
            ans = mid;       // Update the answer
            start = mid + 1; // Try for a larger distance
        }
        else
        {
            end = mid - 1; // Try for a smaller distance
        }
    }
    return ans;
}

int main()
{
    int N = 5, C = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    // Output the largest minimum distance
    cout << getDistance(arr, N, C) << endl;
    return 0;
}
