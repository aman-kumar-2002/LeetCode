/*Given two strings s and t, return true if t is an anagram
(An anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
using all the original letters exactly once) of s, and false otherwise.*/

#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string str1, string str2)
    {
        // Sort both strings
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        // Compare the sorted strings
        if (str1 == str2)
        {
            return true; // Strings are anagrams
        }
        return false; // Strings are not anagrams
    }
};
