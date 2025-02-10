/*The Fibonacci numbers, commonly denoted F(n) form a sequence,
called the Fibonacci sequence, such that each number is the sum of the two preceding ones,
starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).
*/

class Solution
{
public:
    int fibonacci(int num)
    {
        // Base case: If num is 0 or 1, return num itself
        if (num == 0 || num == 1)
        {
            return num;
        }

        // Recursive case: Sum of the two preceding numbers
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
};
