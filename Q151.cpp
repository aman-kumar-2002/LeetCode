/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters.
The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words.
The returned string should only have a single space separating the words.
Do not include any extra spaces.
*/

#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string ans = "";

        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        // Step 2: Process each word
        for (int i = 0; i < n; i++)
        {
            string word = "";
            // Extract each word by skipping spaces
            while (i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }
            // Reverse the individual word
            reverse(word.begin(), word.end());
            // Append the word to the result string
            if (word.length() > 0)
            {
                ans += " " + word;
            }
        }

        // Remove the leading space and return the result
        return ans.substr(1);
    }
};
