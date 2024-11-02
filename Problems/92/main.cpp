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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *prev = new ListNode(0, head);
        ListNode *dummy = prev;
        ListNode *cur = head;
        right -= left;
        while (left-- > 1)
        {
            prev = cur;
            cur = cur->next;
        }
        ListNode *last = cur;
        while (right-- > 0)
        {
            ListNode *tmp = last->next; // 3
            prev->next = tmp;           // 1->3
            last->next = tmp->next;     // 4->2
            tmp->next = cur;            // 3->4
            cur = tmp;                  // 3
        }
        return dummy->next;
    }
};
