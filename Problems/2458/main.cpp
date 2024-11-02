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
    int ni[100005][2];
    vector<vector<int>> cousins;
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        dfs(root);
        bfs(root);

        vector<int> res;
        for (auto &q : queries)
        {
            if (cousins[ni[q][0]].size() == 1)
            {
                int tmp = -1;
                for (auto &c : cousins[ni[q][0] - 1])
                    tmp = max(tmp, ni[c][0]); // since there're only one node in the previous level that has child
                res.push_back(tmp);
            }
            else
            {
                // needed optimization ..
                auto target = q == cousins[ni[q][0]][0] ? cousins[ni[q][0]][1] : cousins[ni[q][0]][0];
                res.push_back(ni[target][0] + ni[target][1]);
            }
        }

        return res;
    }
    int dfs(TreeNode *root)
    {
        if (!root)
            return -1;

        int height = max(dfs(root->left), dfs(root->right));
        ni[root->val][1] = height + 1;
        return height + 1;
    }

    void bfs(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            int len = q.size();
            cousins.push_back({});

            while (len--)
            {
                auto next = q.front();
                q.pop();
                cousins.back().push_back(next->val);

                ni[next->val][0] = depth;
                if (next->left)
                    q.push(next->left);
                if (next->right)
                    q.push(next->right);
            }
            // needed optimization ... or it'll TLE
            sort(cousins.back().begin(), cousins.back().end(), [&](int &a, int &b)
                 { return ni[a][0] + ni[a][1] > ni[b][0] + ni[b][1]; });
            depth++;
        }
    }
};

// 1e9 => O(mn) not works
