/*For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        int minLength = min(str1.size(), str2.size());
        string largestDivisor = "";

        // Try all possible prefixes of the smaller string
        for (int len = 1; len <= minLength; ++len)
        {
            string candidate = str1.substr(0, len);

            // Check if the candidate is a divisor of both strings
            if (isValidDivisor(str1, candidate) && isValidDivisor(str2, candidate))
            {
                largestDivisor = candidate; // Update the largest valid divisor
            }
        }

        return largestDivisor;
    }

private:
    // Helper function to check if 'divisor' divides 'str' completely
    bool isValidDivisor(const string &str, const string &divisor)
    {
        int divisorLength = divisor.size();

        // The length of 'str' must be divisible by the length of 'divisor'
        if (str.size() % divisorLength != 0)
        {
            return false;
        }

        // Construct the repeated version of the divisor
        string repeated = "";
        int repeatCount = str.size() / divisorLength;

        for (int i = 0; i < repeatCount; ++i)
        {
            repeated += divisor;
        }

        // Check if the repeated string matches the original
        return repeated == str;
    }
};
