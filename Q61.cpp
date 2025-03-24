/*Given two binary strings a and b, return their sum as a binary string.*/

#include <string>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int lenA = a.length();
        int lenB = b.length();

        string result; // To store the binary sum

        // Make both strings the same length by padding with leading zeros
        if (lenA < lenB)
        {
            a.insert(0, lenB - lenA, '0');
        }
        if (lenB < lenA)
        {
            b.insert(0, lenA - lenB, '0');
        }

        int maxLen = max(lenA, lenB); // Get the max length
        int carry = 0;

        // Iterate from the end of the strings towards the beginning
        for (int i = maxLen - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0' && carry == 0)
            {
                result.insert(0, 1, '0');
                carry = 0;
            }
            else if (a[i] == '0' && b[i] == '0' && carry == 1)
            {
                result.insert(0, 1, '1');
                carry = 0;
            }
            else if ((a[i] == '0' && b[i] == '1' && carry == 0) ||
                     (a[i] == '1' && b[i] == '0' && carry == 0))
            {
                result.insert(0, 1, '1');
                carry = 0;
            }
            else if ((a[i] == '0' && b[i] == '1' && carry == 1) ||
                     (a[i] == '1' && b[i] == '0' && carry == 1))
            {
                result.insert(0, 1, '0');
                carry = 1;
            }
            else if (a[i] == '1' && b[i] == '1' && carry == 0)
            {
                result.insert(0, 1, '0');
                carry = 1;
            }
            else if (a[i] == '1' && b[i] == '1' && carry == 1)
            {
                result.insert(0, 1, '1');
                carry = 1;
            }
        }

        // Add final carry if it exists
        if (carry)
        {
            result.insert(0, 1, '1');
        }

        return result;
    }
};
