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
#include <cctype>

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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root, nullptr});

        while (!q.empty())
        {
            int len = q.size(), sum = 0;
            vector<pair<TreeNode *, TreeNode *>> tmp;

            while (len-- > 0)
            {
                auto next = q.front();
                q.pop();

                if (next.first)
                {
                    sum += next.first->val;
                    q.push({next.first->left, next.first->right});
                }
                if (next.second)
                {
                    sum += next.second->val;
                    q.push({next.second->left, next.second->right});
                }
                tmp.push_back(next);
            }

            for (auto &p : tmp)
            {
                int pSum = (p.first ? p.first->val : 0) + (p.second ? p.second->val : 0);
                if (p.first)
                    p.first->val = sum - pSum;
                if (p.second)
                    p.second->val = sum - pSum;
            }
        }

        return root;
    }
};
