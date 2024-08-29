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
    bool res = true;
    bool isBalanced(TreeNode *root)
    {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        if (abs(l - r) >= 2)
            res = false;
        return 1 + max(l, r);
    }
};
