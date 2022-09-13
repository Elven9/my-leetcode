#include <stack>

using namespace std;

/**
 * Definition for singly-linked list.
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
    bool isPalindrome(ListNode *head)
    {
        // Naive Solution: Implement w/ an stack but store with half the elements
        // O(n), O(n)
        int len = 0;
        ListNode *cur = head;

        // Check length
        while (cur != nullptr)
        {
            len++;
            cur = cur->next;
        }

        // check
        stack<int> st;
        int halflen = len / 2;
        cur = head;
        for (int i = 0; i < halflen; i++)
        {
            st.push(cur->val);
            cur = cur->next;
        }

        if (len % 2 == 1)
            cur = cur->next;

        while (cur != nullptr)
        {
            if (cur->val != st.top())
            {
                return false;
            }
            st.pop();
            cur = cur->next;
        }
        return true;
    }
};
