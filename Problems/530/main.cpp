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
    int res = INT_MAX;
    int getMinimumDifference(TreeNode *root)
    {
        dfs(root);
        return res;
    }

    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {INT_MIN / 2, INT_MAX / 2};

        auto [lmax, lmin] = dfs(root->left);
        auto [rmax, rmin] = dfs(root->right);

        res = min(res, min(root->val - lmax, rmin - root->val));

        return {rmax == INT_MIN / 2 ? root->val : rmax, lmin == INT_MAX / 2 ? root->val : lmin};
    }
};
