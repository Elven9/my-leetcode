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
    bool isSubtree(TreeNode *r, TreeNode *s)
    {
        if (!r || !s)
            return false;
        if (equal(r, s))
            return true;
        return isSubtree(r->left, s) || isSubtree(r->right, s);
    }

    bool equal(TreeNode *r, TreeNode *s)
    {
        if (r == s)
            return true;
        else if (!r || !s)
            return false;
        else if (r->val != s->val)
            return false;
        else
            return equal(r->left, s->left) && equal(r->right, s->right);
    }
};
