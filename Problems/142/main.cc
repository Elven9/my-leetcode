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
        if (!head)
            return nullptr;

        ListNode *slow = head, *fast = head;

        bool ok = false;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                ok = true;
                break;
            }
        }

        if (!ok)
            return nullptr;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
