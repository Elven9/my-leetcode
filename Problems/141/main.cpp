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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode *slow = head->next, *fast = head->next->next;

        while (slow != nullptr && fast != nullptr)
        {
            if (slow == fast)
                return true;
            slow = slow->next;
            if (fast->next == nullptr)
                break;
            fast = fast->next->next;
        }

        return false;
    }
};
