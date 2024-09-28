#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
#include <sstream>
#include <set>
#include <cctype>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *a = new ListNode(), *b = new ListNode();
        ListNode *ca = a, *cb = b;

        while (head)
        {
            if (head->val < x)
            {
                ca->next = new ListNode(head->val);
                ca = ca->next;
            }
            else
            {
                cb->next = new ListNode(head->val);
                cb = cb->next;
            }
            head = head->next;
        }
        ca->next = b->next;
        return a->next;
    }
};
