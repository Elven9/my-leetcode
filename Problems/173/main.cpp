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

class BSTIterator
{
public:
    TreeNode *r;
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        r = root;
    }

    int next()
    {
        while (true)
        {
            if (r)
            {
                st.push(r);
                r = r->left;
            }
            else
            {
                auto n = st.top();
                st.pop();
                r = n->right;
                return n->val;
            }
        }
        return -1;
    }

    bool hasNext()
    {
        return !st.empty() || r;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
