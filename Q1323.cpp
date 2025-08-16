/*
You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // ---------------------------------------------------
    // 1. Stack-based solution (your approach)
    // ---------------------------------------------------
    int maximum69Number_stack(int num)
    {
        stack<int> digits;
        bool firstChange = true;

        // Extract digits and push into stack
        while (num > 0)
        {
            int digit = num % 10;
            digits.push(digit);
            num /= 10;
        }

        int result = 0;
        // Rebuild number from left to right
        while (!digits.empty())
        {
            int topDigit = digits.top();
            digits.pop();

            if (topDigit == 6 && firstChange)
            {
                result = (result * 10) + 9; // change first 6 → 9
                firstChange = false;
            }
            else
            {
                result = (result * 10) + topDigit;
            }
        }
        return result;
    }

    // ---------------------------------------------------
    // 2. String-based solution (clean & simple)
    // ---------------------------------------------------
    int maximum69Number_string(int num)
    {
        string numStr = to_string(num);

        // Replace the first '6' with '9'
        for (char &ch : numStr)
        {
            if (ch == '6')
            {
                ch = '9';
                break;
            }
        }

        return stoi(numStr);
    }

    // ---------------------------------------------------
    // 3. Math-based solution (optimal, no extra space)
    // ---------------------------------------------------
    int maximum69Number_math(int num)
    {
        int temp = num;
        int position = -1; // stores position of most significant 6
        int index = 0;

        // Find the rightmost position of a 6
        while (temp > 0)
        {
            if (temp % 10 == 6)
            {
                position = index; // update whenever we see a 6
            }
            temp /= 10;
            index++;
        }

        // If we found a 6, add 3 * (10^position) to change it to 9
        if (position != -1)
        {
            num += 3 * pow(10, position);
        }

        return num;
    }

    // ---------------------------------------------------
    // 4. One-liner string trick (short but less readable)
    // ---------------------------------------------------
    int maximum69Number_oneliner(int num)
    {
        string numStr = to_string(num);

        // replace first '6' with '9' if it exists
        size_t pos = numStr.find('6');
        if (pos != string::npos)
        {
            numStr.replace(pos, 1, "9");
        }

        return stoi(numStr);
    }
};
