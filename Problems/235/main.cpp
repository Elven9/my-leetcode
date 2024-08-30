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
        int MIN = min(p->val, q->val), MAX = max(p->val, q->val);
        while (root)
        {
            if (root->val < MIN)
                root = root->right;
            else if (root->val > MAX)
                root = root->left;
            else
                return root;
        }
        return nullptr;
    }
};
