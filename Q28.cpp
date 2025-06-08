/*
Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.
*/

#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        // Fix: Check if haystack is shorter than needle
        if(haystack.length() < needle.length()) return -1;

        for(int i = 0; i <= (int)(haystack.length() - needle.length()); i++)
        {
            bool chk = true;
            for(int j = 0; j < needle.length(); j++)
            {
                if(haystack[i + j] != needle[j])
                {
                    chk = false;
                    break;
                }
            }
            if(chk)
            {
                return i;
            }
        }
        return -1;
    }
};