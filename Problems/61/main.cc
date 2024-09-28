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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;
        int n = 0;
        ListNode *cur = head, *last = head;
        while (cur)
        {
            n++;
            cur = cur->next;
            if (cur)
                last = cur;
        }
        k %= n;
        if (k == 0)
            return head;

        n = n - k - 1;
        cur = head;
        while (n > 0)
        {
            cur = cur->next;
            n--;
        }

        last->next = head;
        head = cur->next;
        cur->next = nullptr;

        return head;
    }
};
