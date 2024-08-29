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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // search
        auto dummy = new TreeNode(0, root, nullptr);
        auto pe = &dummy->left; // parent edge
        auto cur = dummy->left;
        while (cur != nullptr)
        {
            if (key == cur->val)
                break;
            else if (key > cur->val)
            {
                pe = &cur->right;
                cur = cur->right;
            }
            else
            {
                pe = &cur->left;
                cur = cur->left;
            }
        }

        if (cur != nullptr)
        {
            auto l = cur->left, r = cur->right;
            if (l)
            {
                *pe = l;
                auto lr = l->right;
                l->right = cur->right;

                pe = &l->right;
                cur = l->right;
                while (cur)
                {
                    pe = &cur->left;
                    cur = cur->left;
                }
                *pe = lr;
            }
            else if (r)
            {
                *pe = r;
                auto rl = r->left;
                r->left = cur->left;

                pe = &r->left;
                cur = r->left;
                while (cur)
                {
                    pe = &cur->right;
                    cur = cur->right;
                }
                *pe = rl;
            }
            else
            {
                *pe = nullptr;
            }
        }

        return dummy->left;
    }
};
