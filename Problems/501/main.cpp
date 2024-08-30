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
    vector<int> findMode(TreeNode *root)
    {
        unordered_set<int> res;
        int MAX = 1;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto n = q.front();
            q.pop();

            if (res.find(n->val) == res.end())
            {
                auto cnt = countDup(n);
                if (cnt > MAX)
                {
                    MAX = cnt;
                    res.clear();
                }
                if (cnt == MAX)
                    res.insert(n->val);
            }

            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }

        return vector<int>(res.begin(), res.end());
    }

    int countDup(TreeNode *root)
    {
        int T = root->val;
        int res = 1;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto n = q.front();
            q.pop();

            if (n->val == T)
                res++;
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }

        return res;
    }
};
