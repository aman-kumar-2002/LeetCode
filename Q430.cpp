/*You are given a doubly linked list, which contains nodes that have a next pointer,
a previous pointer, and an additional child pointer. This child pointer may
or may not point to a separate doubly linked list, also containing these special nodes.
These child lists may have one or more children of their own, and so on,
to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that
all the nodes appear in a single-level, doubly linked list.
Let curr be a node with a child list. The nodes in the child list
should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list
must have all of their child pointers set to null.*/

#include <iostream>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        Node *current = head;

        while (current != nullptr)
        {
            // If the current node has a child, we need to flatten it
            if (current->child != nullptr)
            {
                Node *nextNode = current->next;            // Store the next node
                Node *childHead = flatten(current->child); // Recursively flatten the child list

                // Connect current node to the head of the flattened child list
                current->next = childHead;
                childHead->prev = current;

                current->child = nullptr; // Remove the child pointer

                // Traverse to the tail of the newly added child list
                Node *childTail = current;
                while (childTail->next != nullptr)
                {
                    childTail = childTail->next;
                }

                // Reconnect the tail of the child list to the original next node
                if (nextNode != nullptr)
                {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
            }

            // Move to the next node
            current = current->next;
        }

        return head;
    }
};
