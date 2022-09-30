#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *stack[100000], *cur;
        int sp = -1, res = 100000;
        stack[++sp] = root;
        bool isFoundp = false, isFoundq = false;

        while (sp >= 0)
        {
            cur = stack[sp];
            if ((isFoundp || isFoundq) && sp < res)
                res = sp;

            // Compromise
            // Original data structure will be destroyed
            if (cur->left != nullptr)
            {
                stack[++sp] = cur->left;
                cur->left = nullptr;
            }
            else if (cur->right != nullptr)
            {
                stack[++sp] = cur->right;
                cur->right = nullptr;
            }
            else
            {
                // Check and Compare
                if (!isFoundp)
                    isFoundp = cur->val == p->val;
                if (!isFoundq)
                    isFoundq = cur->val == q->val;

                if (isFoundp && isFoundq)
                    return stack[res];
                sp--;
            }
        }
        return stack[res];
    }
};
