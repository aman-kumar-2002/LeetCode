/*
There are n gas stations along a circular route,
where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas
to travel from the ith station to its next (i + 1)th station.
You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index
if you can travel around the circuit once in the clockwise direction, otherwise return -1.
If there exists a solution, it is guaranteed to be unique.
*/

#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalGasAvailable = 0;
        int totalGasRequired = 0;

        // Calculate total gas available and total cost required
        for (int fuel : gas)
        {
            totalGasAvailable += fuel;
        }

        for (int expense : cost)
        {
            totalGasRequired += expense;
        }

        // If total gas is less than total cost, the trip is impossible
        if (totalGasAvailable < totalGasRequired)
        {
            return -1;
        }

        int startingStation = 0;
        int currentTank = 0;

        // Try to find the correct starting station
        for (int i = 0; i < gas.size(); i++)
        {
            currentTank += gas[i] - cost[i];

            // If current tank becomes negative, this station can't be a valid start
            if (currentTank < 0)
            {
                startingStation = i + 1;
                currentTank = 0;
            }
        }

        return startingStation;
    }
};
