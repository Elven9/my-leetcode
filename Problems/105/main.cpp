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
    unordered_map<int, int> at;
    TreeNode *buildTree(vector<int> &P, vector<int> &I)
    {
        for (int i = 0; i < I.size(); i++)
            at[I[i]] = i;
        int p = 0;
        return preorder(P, I, p, 0, P.size() - 1);
    }

    TreeNode *preorder(vector<int> &P, vector<int> &I, int &p, int st, int ed)
    {
        if (p >= P.size() || at[P[p]] < st || at[P[p]] > ed)
            return nullptr;
        auto n = new TreeNode(P[p]);
        p++;
        n->left = preorder(P, I, p, st, at[n->val] - 1);
        n->right = preorder(P, I, p, at[n->val] + 1, ed);

        return n;
    }
};
