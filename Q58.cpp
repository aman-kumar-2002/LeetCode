/*Given a string s consisting of words and spaces,
return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.*/

#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.length();     // Get the length of the string
        int lastWordLength = 0; // Initialize the length of the last word
        int index = n - 1;      // Start from the last character

        // Skip trailing spaces
        while (index >= 0 && s[index] == ' ')
        {
            index--;
        }

        // Count the length of the last word
        while (index >= 0 && s[index] != ' ')
        {
            lastWordLength++;
            index--;
        }

        return lastWordLength; // Return the length of the last word
    }
};
