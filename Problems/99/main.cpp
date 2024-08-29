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
    void recoverTree(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *last = new TreeNode(INT_MIN), *first = nullptr, *second = nullptr;

        while (!st.empty() || root)
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                if (root->val < last->val)
                {
                    if (!first)
                        first = last;
                    second = root;
                    // may have only one drop when swap with neighbor node
                }
                last = root;
                root = root->right;
            }
        }
        swap(first->val, second->val);
    }
};

// BST, inorder traversal will be a sequence of non-decreasing numbers;
