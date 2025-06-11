/*
Implement a last-in-first-out (LIFO) stack using only two queues.
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back,
peek/pop from front,size and is empty operations are valid.

Depending on your language, the queue may not be supported natively.
You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/

#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> primaryQueue;
    queue<int> secondaryQueue;

    // Constructor
    MyStack()
    {
        // No initialization needed for queues
    }

    // Push element x onto the stack
    void push(int x)
    {
        // Move all elements from primaryQueue to secondaryQueue
        while (!primaryQueue.empty())
        {
            secondaryQueue.push(primaryQueue.front());
            primaryQueue.pop();
        }

        // Push the new element into primaryQueue
        primaryQueue.push(x);

        // Move all elements back from secondaryQueue to primaryQueue
        while (!secondaryQueue.empty())
        {
            primaryQueue.push(secondaryQueue.front());
            secondaryQueue.pop();
        }
    }

    // Removes the element on top of the stack and returns it
    int pop()
    {
        int topElement = primaryQueue.front();
        primaryQueue.pop();
        return topElement;
    }

    // Get the top element
    int top()
    {
        return primaryQueue.front();
    }

    // Returns whether the stack is empty
    bool empty()
    {
        return primaryQueue.empty();
    }
};

/**
 * Usage:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int popped = obj->pop();
 * int top = obj->top();
 * bool isEmpty = obj->empty();
 */
