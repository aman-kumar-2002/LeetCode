/*You are given two strings word1 and word2.
Merge the strings by adding letters in alternating order,
starting with word1. If a string is longer than the other,
append the additional letters onto the end of the merged string.

Return the merged string.*/

#include <string>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string mergedString = "";   // To store the final merged result
        int index1 = 0, index2 = 0; // Pointers for word1 and word2

        // Merge characters alternately
        while (index1 < word1.size() && index2 < word2.size())
        {
            mergedString += word1[index1++];
            mergedString += word2[index2++];
        }

        // Append remaining characters from word1, if any
        while (index1 < word1.size())
        {
            mergedString += word1[index1++];
        }

        // Append remaining characters from word2, if any
        while (index2 < word2.size())
        {
            mergedString += word2[index2++];
        }

        return mergedString;
    }
};
