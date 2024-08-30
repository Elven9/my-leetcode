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
        vector<TreeNode *> pPath;
        vector<TreeNode *> qPath;
        dfs(root, p, pPath);
        dfs(root, q, qPath);

        int i = 0;
        while (i < pPath.size() && i < qPath.size() && pPath[i] == qPath[i])
            i++;
        return pPath[i - 1];
    }

    bool dfs(TreeNode *root, TreeNode *T, vector<TreeNode *> &path)
    {
        if (!root)
            return false;

        path.push_back(root);
        if (root->val == T->val)
            return true;
        if (dfs(root->left, T, path))
            return true;
        if (dfs(root->right, T, path))
            return true;
        path.pop_back();
        return false;
    }
};
