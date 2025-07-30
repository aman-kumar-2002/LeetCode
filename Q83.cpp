/*Given the head of a sorted linked list,
delete all duplicates such that each element appears only once.
Return the linked list sorted as well.*/

#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Handle empty list
        if (head == nullptr)
            return nullptr;

        // Step 1: Store unique elements from the sorted list into a vector
        vector<int> uniqueValues;
        ListNode *currentNode = head;

        uniqueValues.push_back(currentNode->val); // Add the first value

        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
            if (uniqueValues.back() != currentNode->val)
            {
                uniqueValues.push_back(currentNode->val); // Add only non-duplicate values
            }
        }

        // Step 2: Construct a new linked list from the vector
        ListNode *newHead = new ListNode(uniqueValues[0]);
        ListNode *newCurrent = newHead;

        for (size_t i = 1; i < uniqueValues.size(); ++i)
        {
            newCurrent->next = new ListNode(uniqueValues[i]);
            newCurrent = newCurrent->next;
        }

        return newHead; // Return the head of the new list without duplicates
    }
};

class Solution2
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Handle empty list
        if (head == nullptr)
            return nullptr;

        // Pointer to iterate through the list
        ListNode *currentNode = head;

        while (currentNode != nullptr && currentNode->next != nullptr)
        {
            if (currentNode->val == currentNode->next->val)
            {
                // Duplicate found: skip the next node
                ListNode *duplicateNode = currentNode->next;
                currentNode->next = currentNode->next->next;
                delete duplicateNode; // Free memory of skipped node
            }
            else
            {
                // Move to the next distinct node
                currentNode = currentNode->next;
            }
        }

        return head; // Return the modified original list
    }
};
