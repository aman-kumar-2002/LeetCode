/*Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").

Signedness: Determine the sign by checking if the next character
is '-' or '+', assuming positivity if neither present.

Conversion: Read the integer by skipping leading zeros until a
non-digit character is encountered or the end of the string is reached.
If no digits were read, then the result is 0.

Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
then round the integer to remain in the range. Specifically, integers less than -231
should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

Return the integer as the final result.*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int index = 0;
        int sign = 1;
        long long result = 0;
        bool hasStarted = false;

        // Skip leading whitespaces
        while (str[index] == ' ')
        {
            index++;
        }

        // Handle optional sign (+ or -)
        if (str[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if (str[index] == '+')
        {
            index++;
        }

        // Parse digits and form the number
        while (str[index] >= '0' && str[index] <= '9')
        {
            int digit = str[index] - '0';
            result = result * 10 + digit;

            // Handle overflow for positive numbers
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;
            // Handle overflow for negative numbers
            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;

            index++;
            hasStarted = true;
        }

        // If no digits were parsed, return 0
        if (!hasStarted)
            return 0;

        return result * sign;
    }
};
