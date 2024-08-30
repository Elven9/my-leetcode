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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int res = INT_MIN;
    int longestUnivaluePath(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, root->val);
        return res - 1;
    }

    int dfs(TreeNode *root, int T)
    {
        if (!root)
            return 0;
        int l = dfs(root->left, root->val), r = dfs(root->right, root->val);
        res = max(res, 1 + l + r);
        return root->val == T ? 1 + max(l, r) : 0;
    }
};
