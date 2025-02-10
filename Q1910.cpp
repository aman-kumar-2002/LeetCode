/*Given two strings s and part, perform the following operation
on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.
*/

#include<string>
using namespace std;

class Solution
{
public:
    // Function to remove all occurrences of the substring `part` from the string `s`
    string removeOccurrences(string s, string part)
    {
        // Loop until the string `s` is non-empty and the substring `part` is found in `s`
        while (s.length() > 0 && s.find(part) < s.length())
        {
            // Find the starting index of the substring `part` in `s`
            size_t pos = s.find(part);

            // Remove the substring `part` from `s` starting at index `pos`
            s.erase(pos, part.length());
        }
        // Return the final string after all occurrences of `part` are removed
        return s;
    }
};
