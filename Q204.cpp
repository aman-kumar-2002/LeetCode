/*Given an integer n, return the number of prime numbers that are strictly less than n.*/

#include<vector>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        // If n is less than 2, there are no prime numbers
        if (n <= 2)
            return 0;

        // Create a boolean vector `isPrime` and initialize all entries to `true`
        vector<bool> isPrime(n, true);

        // 0 and 1 are not prime numbers
        isPrime[0] = false;
        isPrime[1] = false;

        // Use Sieve of Eratosthenes to mark non-prime numbers
        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i])
            {
                // Mark multiples of `i` starting from `i * i` as non-prime
                for (int j = i * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        // Count the number of primes
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                count++;
            }
        }

        return count;
    }
};
