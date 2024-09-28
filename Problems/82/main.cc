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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *res = new ListNode(-101, head);
        ListNode *last = res;
        while (last->next)
        {
            ListNode *next = last->next->next;
            while (next && next->val == last->next->val)
                next = next->next;

            if (next != last->next->next)
            {
                last->next = next;
                continue;
            }
            last = last->next;
        }

        return res->next;
    }
};
