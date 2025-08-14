/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3^x.
*/

class Solution
{
public:
    bool isPowerOfThree(int number)
    {
        // Negative numbers, zero, and non-positive numbers cannot be a power of three
        if (number <= 0)
            return false;

        // Keep dividing the number by 3 as long as it is divisible by 3
        while (number % 3 == 0)
        {
            number /= 3; // Reduce the number by a factor of 3
        }

        // If we end up with 1, it means the original number was a power of 3
        return number == 1;
    }
};
