/*You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty,
and an integer n, return true if n new flowers can be planted in the flowerbed
without violating the no-adjacent-flowers rule and false otherwise.*/

#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int flowersToPlant)
    {
        int plantedCount = 0;        // Count of flowers that can be planted
        int size = flowerbed.size(); // Size of the flowerbed array

        for (int i = 0; i < size; i++)
        {
            // Check if the current spot is empty and its neighbors (if any) are also empty
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0))
            {

                flowerbed[i] = 1; // Plant a flower at the current spot
                plantedCount++;   // Increment the planted flower count
                i++;              // Skip the next spot to avoid consecutive planting
            }

            // If the required number of flowers are planted, return true
            if (plantedCount >= flowersToPlant)
            {
                return true;
            }
        }

        // Return true if the required number of flowers were planted, otherwise false
        return plantedCount >= flowersToPlant;
    }
};
