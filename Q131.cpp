/*Given a string s, partition s such that every
substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.*/

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to check if a given string is a palindrome
    bool isPalindrome(const string &str)
    {
        int left = 0, right = str.size() - 1;
        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    // Recursive function to find all palindrome partitions of the string
    void findPalindromePartitions(string remainingStr, vector<string> &currentPartition, vector<vector<string>> &result)
    {
        // If there are no remaining characters, add the current partition to the result
        if (remainingStr.empty())
        {
            result.push_back(currentPartition);
            return;
        }

        // Try all possible partitions
        for (int i = 0; i < remainingStr.size(); i++)
        {
            string prefix = remainingStr.substr(0, i + 1); // Extract prefix substring

            // Check if the prefix is a palindrome
            if (isPalindrome(prefix))
            {
                currentPartition.push_back(prefix);                                             // Add palindrome to the current partition
                findPalindromePartitions(remainingStr.substr(i + 1), currentPartition, result); // Recur with remaining string
                currentPartition.pop_back();                                                    // Backtrack to explore other partitions
            }
        }
    }

    // Function to return all possible palindrome partitions of the input string
    vector<vector<string>> partition(string inputStr)
    {
        vector<vector<string>> result;   // Stores the final list of palindrome partitions
        vector<string> currentPartition; // Stores the current partition being explored
        findPalindromePartitions(inputStr, currentPartition, result);
        return result;
    }
};
