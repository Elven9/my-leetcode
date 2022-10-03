#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // Tortoise-Hare Algorithm
        // O(n), O(1)
        if (!head)
            return nullptr;
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
    ListNode *detectCycle_naive(ListNode *head)
    {
        // Naive solution, w/ map: O(n), O(n)
        map<ListNode *, bool> pmap;
        ListNode *cur = head;
        while (cur)
        {
            if (pmap.count(cur))
                return cur;
            else
                pmap[cur] = true;
            cur = cur->next;
        }
        return nullptr;
    }
};
