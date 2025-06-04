/*Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days
(starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2,
then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8,
then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner
{
private:
    vector<int> priceHistory; // Stores all prices seen so far
    stack<int> indexStack;    // Stack to store indices of previous higher prices

public:
    StockSpanner()
    {
        // Initialization (nothing needed here for now)
    }

    int next(int currentPrice)
    {
        // Add today's price to the history
        priceHistory.push_back(currentPrice);
        int currentIndex = priceHistory.size() - 1;

        // Remove all indices from the stack where the price is less than or equal to currentPrice
        while (!indexStack.empty() && priceHistory[indexStack.top()] <= currentPrice)
        {
            indexStack.pop();
        }

        int span;

        // If no previous higher price, span is the entire length so far
        if (indexStack.empty())
        {
            span = currentIndex + 1;
        }
        else
        {
            // Else, span is the distance from the last higher price
            span = currentIndex - indexStack.top();
        }

        // Push current day's index onto the stack
        indexStack.push(currentIndex);

        return span;
    }
};
