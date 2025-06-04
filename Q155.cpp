/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/
#include <stack>
#include <climits>
using namespace std;

class MinStack
{
    stack<long long> dataStack; // Stack to store actual and encoded values
    long long currentMin;       // Stores the current minimum value

public:
    MinStack()
    {
        currentMin = LLONG_MAX; // Initialize min to max possible
    }

    // Push a new value onto the stack
    void push(int value)
    {
        if (dataStack.empty())
        {
            // First element, no encoding needed
            dataStack.push(value);
            currentMin = value;
        }
        else
        {
            if (value >= currentMin)
            {
                // Normal value, push directly
                dataStack.push(value);
            }
            else
            {
                // New min found, encode previous min in the pushed value
                long long encodedValue = 2LL * value - currentMin;
                dataStack.push(encodedValue);
                currentMin = value; // Update current min
            }
        }
    }

    // Pop the top value from the stack
    void pop()
    {
        if (dataStack.empty())
            return;

        long long topValue = dataStack.top();
        dataStack.pop();

        if (topValue < currentMin)
        {
            // This was an encoded value → retrieve previous min
            currentMin = 2LL * currentMin - topValue;
        }
        // Else: popped value was normal, currentMin stays unchanged
    }

    // Get the top element without removing it
    int top()
    {
        if (dataStack.empty())
            return -1;

        long long topValue = dataStack.top();
        if (topValue >= currentMin)
        {
            // Normal value
            return topValue;
        }
        else
        {
            // Encoded value, actual top is currentMin
            return currentMin;
        }
    }

    // Retrieve the current minimum in O(1)
    int getMin()
    {
        if (dataStack.empty())
            return -1;
        return currentMin;
    }
};
