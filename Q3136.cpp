/*
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false.

Notes:

'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
*/

#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string word)
    {
        // A valid word must have at least 3 characters
        if (word.length() < 3)
        {
            return false;
        }

        bool containsVowel = false;     // To track presence of at least one vowel
        bool containsConsonant = false; // To track presence of at least one consonant

        for (char character : word)
        {
            // Word should contain only letters and digits
            if (!isalnum(character))
            {
                return false;
            }

            // Check if the character is a letter
            if (isalpha(character))
            {
                // Convert to lowercase to simplify vowel check
                char lowerChar = tolower(character);

                // Check if the character is a vowel
                if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u')
                {
                    containsVowel = true;
                }
                else
                {
                    containsConsonant = true;
                }
            }
        }

        // Valid only if it contains at least one vowel and one consonant
        return containsVowel && containsConsonant;
    }
};
