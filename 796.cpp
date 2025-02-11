/*Given two strings s and goal, return true if and only if
s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost
character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
*/

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        // Check if the lengths are different
        if (s.length() != goal.length())
            return false;

        // Concatenate s with itself to cover all possible rotations
        string doubled = s + s;

        // Check if goal is a substring of the doubled string
        return doubled.find(goal) != string::npos;
    }
};
