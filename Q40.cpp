/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?*/

#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        // Base cases
        if (n <= 1)
            return 1;

        // Variables to track the number of ways to reach the previous two steps
        int oneStepBefore = 1;  // Ways to reach (n-1)th step
        int twoStepsBefore = 1; // Ways to reach (n-2)th step
        int totalWays;

        // Iteratively calculate the number of ways to reach each step
        for (int step = 2; step <= n; ++step)
        {
            totalWays = oneStepBefore + twoStepsBefore; // Ways to reach current step
            twoStepsBefore = oneStepBefore;             // Move forward
            oneStepBefore = totalWays;
        }

        return oneStepBefore; // Return the total ways to reach the nth step
    }
};
