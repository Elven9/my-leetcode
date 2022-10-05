#include <vector>
#include <iostream>
#include <string>

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
    vector<int> rightSideView(TreeNode *root)
    {
        // Problem Elaboration: If right branch is longer than left, traverse right
        // Preorder traversal, level override
        // No optimization
        vector<int> res;
        preorder(root, res, 0);

        return res;
    }

    void preorder(TreeNode *root, vector<int> &res, int level)
    {
        if (!root)
            return;

        // Update result array
        if (res.size() <= level)
            res.push_back(root->val);
        else
            res[level] = root->val;

        preorder(root->left, res, level + 1);
        preorder(root->right, res, level + 1);
    }
};
