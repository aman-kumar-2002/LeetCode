/*You are given an array prices where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.
*/
#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; // Maximum profit achievable
        int bestBuy = prices[0]; // Minimum price to buy

        for (int i = 1; i < prices.size(); i++) {
            // Check the profit if we sell on the current day
            maxProfit = max(maxProfit, prices[i] - bestBuy);
            // Update the minimum price to buy
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};
