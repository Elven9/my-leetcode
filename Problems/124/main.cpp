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
    int maxPathSum(TreeNode *root)
    {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = dfs(root->left), r = dfs(root->right);
        res = max(res, root->val + r + l);
        return max(max(l, r) + root->val, max(root->val, 0));
    }
};
