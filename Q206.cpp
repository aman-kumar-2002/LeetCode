#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list node.
 */
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *previousNode = nullptr; // Will become the new head after reversal
        ListNode *currentNode = head;     // Used to traverse the original list
        ListNode *nextNode = nullptr;     // Temporarily stores the next node

        while (currentNode != nullptr)
        {
            nextNode = currentNode->next;     // Save next node
            currentNode->next = previousNode; // Reverse the pointer
            previousNode = currentNode;       // Move previous one step forward
            currentNode = nextNode;           // Move current one step forward
        }

        return previousNode; // New head of the reversed list
    }
};
