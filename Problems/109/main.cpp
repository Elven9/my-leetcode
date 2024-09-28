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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        int n = 0;
        ListNode *cur = head;
        while (cur)
        {
            n++;
            cur = cur->next;
        }
        return construct(head, n);
    }

    TreeNode *construct(ListNode *head, int n)
    {
        if (n == 0)
            return nullptr;
        int mid = (n - 1) / 2;

        ListNode *cur = head;
        for (int i = 0; i < mid; i++)
            cur = cur->next;
        TreeNode *root = new TreeNode(cur->val);
        root->left = construct(head, mid);
        root->right = construct(cur->next, n - mid - 1);
        return root;
    }
};
