/*
You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
*/

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int n = num.length();
        string largest = ""; // stores the largest good triple found

        // Loop until the third last character
        for (int i = 0; i <= n - 3; i++)
        {
            // Check if current and next two characters are the same
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
            {
                string triple = num.substr(i, 3);

                // If largest is empty or current triple is bigger, update
                if (largest.empty() || triple > largest)
                {
                    largest = triple;
                }
            }
        }

        return largest; // returns "" if no triple found
    }
};
