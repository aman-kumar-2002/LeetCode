/*Given two strings s1 and s2, return true if s2 contains a
permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.
*/

#include<string>
using namespace std;

class Solution
{
public:
    bool isfreqsame(int freq1[], int freq2[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
            {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2)
    {
        // If s1 is longer than s2, return false
        if (s1.length() > s2.length())
        {
            return false;
        }

        int freq[26] = {0};
        int winfreq[26] = {0};

        // Populate the frequency array for s1
        for (char c : s1)
        {
            freq[c - 'a']++;
        }

        // Initialize the first window in s2
        int winsize = s1.length();
        for (int i = 0; i < winsize; i++)
        {
            winfreq[s2[i] - 'a']++;
        }

        // Check if the first window matches
        if (isfreqsame(freq, winfreq))
        {
            return true;
        }

        // Slide the window across s2
        for (int i = winsize; i < s2.length(); i++)
        {
            winfreq[s2[i] - 'a']++;           // Add new character to the window
            winfreq[s2[i - winsize] - 'a']--; // Remove character that is out of the window

            if (isfreqsame(freq, winfreq))
            { // Check if the current window matches
                return true;
            }
        }

        return false; // No permutation found
    }
};
