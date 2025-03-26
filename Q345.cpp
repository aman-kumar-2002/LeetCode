/*Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.*/

#include <string>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int left = 0, right = s.length() - 1; // Pointers for both ends

        while (left <= right)
        {
            char leftChar = s.at(left);
            char rightChar = s.at(right);

            // Check if the character on the left is a vowel
            if (leftChar == 'a' || leftChar == 'e' || leftChar == 'i' || leftChar == 'o' || leftChar == 'u' ||
                leftChar == 'A' || leftChar == 'E' || leftChar == 'I' || leftChar == 'O' || leftChar == 'U')
            {

                // Check if the character on the right is a vowel
                if (rightChar == 'a' || rightChar == 'e' || rightChar == 'i' || rightChar == 'o' || rightChar == 'u' ||
                    rightChar == 'A' || rightChar == 'E' || rightChar == 'I' || rightChar == 'O' || rightChar == 'U')
                {

                    // Swap vowels
                    swap(s.at(left), s.at(right));
                    left++;
                    right--;
                }
                else
                {
                    // Move the right pointer if it is not a vowel
                    right--;
                }
            }
            else
            {
                // Move the left pointer if it is not a vowel
                left++;
            }
        }

        return s; // Return the string with reversed vowels
    }
};
