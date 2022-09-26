#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        // O(n), O(1) solution
        // Scan first and create duplicate node
        Node *cur = head;
        while (cur != nullptr)
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        // Assign Random Links
        cur = head;
        while (cur != nullptr)
        {
            cur->next->random = cur->random == nullptr ? nullptr : cur->random->next;
            cur = cur->next->next;
        }

        // Extract New List
        Node *newHead = head->next;
        cur = head;
        while (cur != nullptr)
        {
            Node *tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = cur->next == nullptr ? nullptr : cur->next->next;
            cur = cur->next;
        }

        return newHead;
    }
};
