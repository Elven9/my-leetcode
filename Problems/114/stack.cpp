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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        TreeNode *cur = new TreeNode();
        stack<TreeNode *> st;

        st.push(root);
        while (!st.empty())
        {
            auto n = st.top();
            st.pop();

            cur->right = n;
            cur = cur->right;
            if (n->right)
                st.push(n->right);
            if (n->left)
                st.push(n->left);
            cur->left = cur->right = nullptr;
        }
    }
};
