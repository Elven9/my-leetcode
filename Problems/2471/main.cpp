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
    int minimumOperations(TreeNode *root)
    {
        queue<TreeNode *> q;
        int res = 0;

        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            vector<pair<int, int>> k;
            for (int i = 0; i < len; i++)
            {
                auto f = q.front();
                q.pop();

                k.push_back({f->val, i});
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }

            sort(k.begin(), k.end());

            for (int i = 0; i < len; i++)
                while (k[i].second != i)
                {
                    // reverse sort
                    swap(k[i], k[k[i].second]);
                    res++;
                }
        }

        return res;
    }
};

// minimum swap => insertion sort

// 4 2 3 0 1
