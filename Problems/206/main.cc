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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;

        // 用下面這種在 lc 上會 uaf 點點點
        // ListNode *cur=head->next, *last=head;
        // while (cur) {
        //     ListNode *next = cur->next;
        //     cur->next=last;
        //     last=cur;
        //     cur=next;
        // }

        ListNode *res = new ListNode(head->val);
        ListNode *cur = head->next;
        while (cur) {
            ListNode *newNode = new ListNode(cur->val);
            newNode->next=res;
            res=newNode;
            cur=cur->next;
        }

        return res;
    }
};
