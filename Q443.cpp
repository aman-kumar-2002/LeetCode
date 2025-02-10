/*Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately,
but instead, be stored in the input character array chars.
Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
*/

#include <vector>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        // Get the size of the input character array
        int n = chars.size();
        // Index to keep track of the position in the modified array
        int idx = 0;

        // Iterate through the input array
        for (int i = 0; i < n; i++)
        {
            // Store the current character
            char ch = chars[i];
            // Initialize a counter to count occurrences of the character
            int count = 0;

            // Count the occurrences of the current character
            while (i < n && chars[i] == ch)
            {
                count++;
                i++;
            }

            // If the count is 1, simply store the character
            if (count == 1)
            {
                chars[idx++] = ch;
            }
            else
            {
                // Otherwise, store the character followed by its count
                chars[idx++] = ch;
                // Convert the count to a string
                string str = to_string(count);
                // Store each digit of the count in the array
                for (char dig : str)
                {
                    chars[idx++] = dig;
                }
            }
            // Adjust the index since the outer loop also increments it
            i--;
        }

        // Resize the array to contain only the compressed result
        chars.resize(idx);
        // Return the new length of the compressed array
        return idx;
    }
};
