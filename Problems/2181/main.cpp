#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *ret = head, *cur = head;
        head = head->next;
        while (head != nullptr)
        {
            while (head->val != 0)
            {
                cur->val += head->val;
                head = head->next;
            }
            if (head->next != nullptr)
            {
                cur->next = head;
                cur = cur->next;
            }
            else
            {
                cur->next = nullptr;
            }
            head = head->next;
        }
        return ret;
    }
};
