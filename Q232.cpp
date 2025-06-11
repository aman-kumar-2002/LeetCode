/*
Implement a first in first out (FIFO) queue using only two stacks.
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top,
peek/pop from top, size, and is empty operations are valid.

Depending on your language, the stack may not be supported natively.
You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/

#include <stack>
using namespace std;

class MyQueue
{
public:
    stack<int> inputStack;
    stack<int> tempStack;

    // Constructor
    MyQueue()
    {
        // No initialization needed for stacks
    }

    // Push element x to the back of the queue
    void push(int x)
    {
        // Move all elements from inputStack to tempStack
        while (!inputStack.empty())
        {
            tempStack.push(inputStack.top());
            inputStack.pop();
        }

        // Push the new element into inputStack
        inputStack.push(x);

        // Move all elements back from tempStack to inputStack
        while (!tempStack.empty())
        {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }
    }

    // Removes the element from the front of the queue and returns it
    int pop()
    {
        int frontElement = inputStack.top();
        inputStack.pop();
        return frontElement;
    }

    // Get the front element
    int peek()
    {
        return inputStack.top();
    }

    // Returns whether the queue is empty
    bool empty()
    {
        return inputStack.empty();
    }
};

/**
 * Usage:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int front = obj->pop();
 * int peeked = obj->peek();
 * bool isEmpty = obj->empty();
 */
