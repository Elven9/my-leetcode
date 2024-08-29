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
    int countNodes(TreeNode *root)
    {
        queue<TreeNode *> q;
        int res = 0;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            auto n = q.front();
            res++;
            q.pop();
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        return res;
    }
};
