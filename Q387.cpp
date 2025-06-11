/*
Given a string s, find the first non-repeating character in it
and return its index. If it does not exist, return -1.
*/
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> charFrequency; // To count frequency of each character
        queue<int> indexQueue;                  // To store indices of characters in the order they appear

        for (int i = 0; i < s.size(); i++)
        {
            char currentChar = s[i];

            // If character is seen for the first time, store its index
            if (charFrequency.find(currentChar) == charFrequency.end())
            {
                indexQueue.push(i);
            }

            // Increment frequency of the character
            charFrequency[currentChar]++;

            // Remove characters from the front of the queue if they are no longer unique
            while (!indexQueue.empty() && charFrequency[s[indexQueue.front()]] > 1)
            {
                indexQueue.pop();
            }
        }

        // Return index of first unique character if found, else -1
        return indexQueue.empty() ? -1 : indexQueue.front();
    }
};
