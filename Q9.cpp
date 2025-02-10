/*Given an integer x, return true if x is a
palindrome, and false otherwise.*/

class Solution
{
public:
    // Function to check if a given number is a palindrome
    bool isPalindrome(long n)
    {
        // Store the original number for comparison
        long originalNumber = n;

        // Variable to store the reversed number
        long reversedNumber = 0;

        // Extract digits from the number and reverse it
        while (n > 0)
        {
            int remainder = n % 10;                             // Get the last digit of the number
            reversedNumber = (reversedNumber * 10) + remainder; // Build the reversed number
            n = n / 10;                                         // Remove the last digit from the number
        }

        // Check if the reversed number is equal to the original number
        if (originalNumber == reversedNumber)
            return true; // The number is a palindrome
        else
            return false; // The number is not a palindrome
    }
};
