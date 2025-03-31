/*Given a string s and an integer k, reverse the first k characters
for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them.
If there are less than 2k but greater than or equal to k characters,
then reverse the first k characters and leave the other as original.*/

#include <algorithm> // For reverse()
#include <string>
using namespace std;

class Solution
{
public:
    string reverseStr(string input, int blockSize)
    {
        int length = input.length();

        // Iterate over the string in steps of 2 * blockSize
        for (int start = 0; start < length; start += 2 * blockSize)
        {

            // Find the end position of the section to reverse
            int end = min(start + blockSize, length);

            // Reverse the first blockSize characters in every 2 * blockSize block
            reverse(input.begin() + start, input.begin() + end);
        }

        return input;
    }
};
