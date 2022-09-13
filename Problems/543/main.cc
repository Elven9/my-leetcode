/**
 * Definition for a binary tree node.
 */
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
    struct RecuRes
    {
        int best;
        int oneway;
    };

    int diameterOfBinaryTree(TreeNode *root)
    {
        return getDiameter(root).best;
    }

    RecuRes getDiameter(TreeNode *node)
    {
        if (node == nullptr)
        {
            return RecuRes{0, -1};
        }
        RecuRes left = getDiameter(node->left);
        RecuRes right = getDiameter(node->right);
        int in = left.oneway + right.oneway + 2;
        int cbest = left.best > right.best ? left.best : right.best;
        return RecuRes{
            in > cbest ? in : cbest,
            (left.oneway > right.oneway ? left.oneway : right.oneway) + 1};
    }
};
