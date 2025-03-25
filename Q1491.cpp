/*You are given an array of unique integers salary where salary[i]
is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary.
Answers within 10-5 of the actual answer will be accepted.*/

#include <vector>
#include <algorithm> // For sort()
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        // Sort the salary array
        sort(salary.begin(), salary.end());

        double totalSum = 0.0; // To accumulate the valid salaries

        // Accumulate salaries excluding the minimum and maximum
        for (int i = 1; i < salary.size() - 1; i++)
        {
            totalSum += salary[i];
        }

        // Calculate the average
        double averageSalary = totalSum / (salary.size() - 2);

        return averageSalary;
    }
};
