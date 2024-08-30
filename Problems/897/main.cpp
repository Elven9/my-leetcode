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

struct TreeNode {
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
    TreeNode *increasingBST(TreeNode *root)
    {
        auto dummy = new TreeNode();
        auto cur = dummy;

        stack<TreeNode *> st;

        while (!st.empty() || root)
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                auto n = st.top();
                st.pop();
                root = n->right;
                cur->right = new TreeNode(n->val);
                cur = cur->right;
            }
        }

        return dummy->right;
    }
};
