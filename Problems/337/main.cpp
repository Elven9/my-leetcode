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
    unordered_map<TreeNode *, int> memo;
    unordered_map<TreeNode *, int> memoNot;
    int rob(TreeNode *root)
    {
        return dfs(root, false);
    }

    int dfs(TreeNode *root, bool robParent)
    {
        if (!root)
            return 0;
        if (robParent && memo.find(root) != memo.end())
            return memo[root];
        if (!robParent && memoNot.find(root) != memoNot.end())
            return memoNot[root];

        int not_rob = dfs(root->left, false) + dfs(root->right, false);
        int rob = !robParent ? root->val + dfs(root->left, true) + dfs(root->right, true) : 0;

        int res = max(not_rob, rob);
        if (robParent)
            memo[root] = res;
        else
            memoNot[root] = res;
        return res;
    }
};
