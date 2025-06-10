/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache. If the number of keys
exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/

#include <unordered_map>
using namespace std;

// Node structure for the doubly linked list
struct ListNode
{
    int key, value;
    ListNode *prev;
    ListNode *next;

    ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int maxCapacity;
    unordered_map<int, ListNode *> cacheMap; // Maps key -> node pointer
    ListNode *dummyHead;
    ListNode *dummyTail;

    // Remove a node from its current position in the list
    void removeNode(ListNode *node)
    {
        ListNode *prevNode = node->prev;
        ListNode *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert a node right after the dummy head (mark as most recently used)
    void insertAtFront(ListNode *node)
    {
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next->prev = node;
        dummyHead->next = node;
    }

public:
    // Constructor to initialize cache with given capacity
    LRUCache(int capacity)
    {
        maxCapacity = capacity;
        dummyHead = new ListNode(-1, -1); // Dummy head node
        dummyTail = new ListNode(-1, -1); // Dummy tail node
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    // Get the value of a key if present, else return -1
    int get(int key)
    {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        // Move the accessed node to the front
        ListNode *node = cacheMap[key];
        removeNode(node);
        insertAtFront(node);
        return node->value;
    }

    // Add or update a key-value pair in the cache
    void put(int key, int value)
    {
        if (cacheMap.find(key) != cacheMap.end())
        {
            // Key already exists, update the value and move to front
            ListNode *node = cacheMap[key];
            node->value = value;
            removeNode(node);
            insertAtFront(node);
        }
        else
        {
            // New key; check if capacity exceeded
            if (cacheMap.size() == maxCapacity)
            {
                // Remove the least recently used node (before dummy tail)
                ListNode *lruNode = dummyTail->prev;
                removeNode(lruNode);
                cacheMap.erase(lruNode->key);
                delete lruNode;
            }
            // Insert the new node at the front
            ListNode *newNode = new ListNode(key, value);
            insertAtFront(newNode);
            cacheMap[key] = newNode;
        }
    }
};
