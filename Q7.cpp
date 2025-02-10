/*Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).*/

#include<limits.h>

class Solution {
public:
    int reverse(int x) {
        int rem = 0;  // To store the remainder (last digit of `x`)
        int sum = 0;  // To store the reversed number

        while (x != 0) {
            rem = x % 10;  // Extract the last digit
            
            // Check for overflow/underflow before updating `sum`
            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && rem > 7)) {
                return 0;  // Overflow
            }
            if (sum < INT_MIN / 10 || (sum == INT_MIN / 10 && rem < -8)) {
                return 0;  // Underflow
            }

            // Update `sum` with the reversed number
            sum = (sum * 10) + rem;

            // Remove the last digit from `x`
            x = x / 10;
        }

        return sum;
    }
};
