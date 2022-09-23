#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Definition for a binary tree node.
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
        if (root == nullptr)
            return;
        // Simple Recursive Preorder Traversal
        // Maxima height of a tree will be 2000
        // Naive Solution

        TreeNode *right = root->right;
        root->right = root->left;
        root->left = nullptr;
        flatten(root->right);

        // Traversal to the end of right branch
        TreeNode *tmp = root;
        while (tmp->right != nullptr)
            tmp = tmp->right;

        tmp->right = right;
        flatten(tmp->right);
    }
};
