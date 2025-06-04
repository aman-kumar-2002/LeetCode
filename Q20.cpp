/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string brackets)
    {
        stack<char> openBrackets;
        int index = 0;

        // Empty string is considered invalid
        if (brackets.length() <= 0)
        {
            return false;
        }

        // Traverse each character in the string
        while (index < brackets.length())
        {
            char current = brackets[index];

            // Push opening brackets onto the stack
            if (current == '{' || current == '(' || current == '[')
            {
                openBrackets.push(current);
            }
            // Handle closing brackets
            else if (current == '}' || current == ')' || current == ']')
            {
                // If there's no corresponding opening bracket
                if (openBrackets.empty())
                {
                    return false;
                }

                // Check for matching opening bracket
                if ((current == '}' && openBrackets.top() == '{') ||
                    (current == ')' && openBrackets.top() == '(') ||
                    (current == ']' && openBrackets.top() == '['))
                {
                    openBrackets.pop(); // Match found, remove opening bracket
                }
                else
                {
                    return false; // Mismatch
                }
            }

            index++;
        }

        // If stack is empty, all brackets were matched
        return openBrackets.empty();
    }
};
