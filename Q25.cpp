/*Given the head of a linked list, reverse the nodes of the list k at a time,
and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.*/

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *current = head;
        int nodeCount = 0;

        // Check if there are at least k nodes ahead to reverse
        while (nodeCount < k)
        {
            if (current == nullptr)
            {
                // If fewer than k nodes remain, return head without reversing
                return head;
            }
            current = current->next;
            nodeCount++;
        }

        // Recursively reverse the next k-group
        ListNode *reversedHead = reverseKGroup(current, k);

        // Reverse current k nodes
        current = head;
        nodeCount = 0;

        while (nodeCount < k)
        {
            ListNode *nextNode = current->next; // Save next node
            current->next = reversedHead;       // Point current node to the reversed part
            reversedHead = current;             // Move the reversed head to current
            current = nextNode;                 // Move to next node
            nodeCount++;
        }

        return reversedHead; // Return new head after reversing k-group
    }
};
