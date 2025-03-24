/*Reverse bits of a given 32 bits unsigned integer.*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        string binary = "";

        // Convert integer to binary manually
        for (int i = 0; i < 32; ++i)
        {
            if (n % 2 == 0)
            {
                binary += '0'; // Append '0' for even
            }
            else
            {
                binary += '1'; // Append '1' for odd
            }
            n /= 2; // Divide by 2 to shift bits
        }

        // Convert reversed binary back to integer
        uint32_t result = 0;
        uint32_t power = 1; // 2^0 initially

        for (int i = binary.length() - 1; i >= 0; --i)
        {
            if (binary[i] == '1')
            {
                result += power; // Add the corresponding power of 2
            }
            power *= 2; // Move to the next power of 2
        }

        return result;
    }
};
