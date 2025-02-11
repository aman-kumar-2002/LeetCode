/*Given a string paragraph and a string array of the banned words banned,
return the most frequent word that is not banned.
It is guaranteed there is at least one word that is not banned,
and that the answer is unique.

The words in paragraph are case-insensitive and the answer
should be returned in lowercase.*/

#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;
        string word, mostCommon;
        int maxCount = 0;

        // Convert paragraph to lowercase and process words
        for (char &c : paragraph)
        {
            if (isalpha(c))
            {
                c = tolower(c);
            }
            else
            {
                c = ' '; // Replace punctuation with space
            }
        }

        stringstream ss(paragraph);
        while (ss >> word)
        {
            if (bannedSet.find(word) == bannedSet.end())
            {
                freq[word]++;
                if (freq[word] > maxCount)
                {
                    maxCount = freq[word];
                    mostCommon = word;
                }
            }
        }

        return mostCommon;
    }
};
