/*Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)*/

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
    ListNode *swapPairs(ListNode *head)
    {
        // If the list has 0 or 1 node, return it as is
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *current = head;
        ListNode *newHead = head->next; // After the first swap, this will be the new head
        ListNode *previousPairTail = nullptr;

        // Traverse the list in pairs
        while (current != nullptr && current->next != nullptr)
        {
            ListNode *firstNode = current;
            ListNode *secondNode = current->next;
            ListNode *nextPairHead = secondNode->next;

            // Swap the current pair
            secondNode->next = firstNode;
            firstNode->next = nextPairHead;

            // Link the previous pair with the current swapped pair
            if (previousPairTail != nullptr)
            {
                previousPairTail->next = secondNode;
            }

            // Update the tail for the next iteration
            previousPairTail = firstNode;
            current = nextPairHead;
        }

        return newHead;
    }
};
