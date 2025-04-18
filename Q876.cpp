/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.*/

#include <iostream>
using namespace std;
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
    ListNode *middleNode(ListNode *head)
    {
        // 'slowPointer' will move one step at a time
        ListNode *slowPointer = head;

        // 'fastPointer' will move two steps at a time
        ListNode *fastPointer = head;

        // Traverse the list
        while (fastPointer != nullptr && fastPointer->next != nullptr)
        {
            slowPointer = slowPointer->next;       // move one step
            fastPointer = fastPointer->next->next; // move two steps
        }

        // When fastPointer reaches the end, slowPointer will be at the middle
        return slowPointer;
    }
};
