/*
Given an array of intervals where intervals[i] = [starti, endi],
merge all overlapping intervals, and return an array of the non-overlapping intervals
that cover all the intervals in the input.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // Sort intervals by their start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;

        for (int i = 0; i < intervals.size(); i++)
        {
            // If mergedIntervals is empty or no overlap with the last merged interval
            if (mergedIntervals.empty() || intervals[i][0] > mergedIntervals.back()[1])
            {
                mergedIntervals.push_back(intervals[i]); // Add current interval as is
            }
            else
            {
                // Overlapping intervals, so merge by updating the end time
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }

        return mergedIntervals;
    }
};
