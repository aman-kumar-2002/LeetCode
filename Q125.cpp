/*A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include<string>
using namespace std;

class Solution {
public:
    // Helper function to check if a character is alphanumeric
    bool isValidCharacter(char ch) {
        return (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z');
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int st = 0, end = n - 1;

        while (st < end) {
            // Skip non-alphanumeric characters
            while (st < end && !isValidCharacter(s[st])) {
                st++;
            }
            while (st < end && !isValidCharacter(s[end])) {
                end--;
            }

            // Compare characters (case insensitive)
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};
