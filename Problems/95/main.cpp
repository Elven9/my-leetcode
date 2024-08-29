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
    vector<TreeNode *> generateTrees(int n)
    {
        return construct(1, n);
    }

    vector<TreeNode *> construct(int st, int ed)
    {
        if (st > ed)
            return {nullptr};

        vector<TreeNode *> res;
        for (int i = st; i <= ed; i++)
        {
            auto L = construct(st, i - 1);
            auto R = construct(i + 1, ed);

            for (auto l : L)
                for (auto r : R)
                {
                    auto root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
        }

        return res;
    }
};
