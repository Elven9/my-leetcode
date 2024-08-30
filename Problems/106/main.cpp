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

class Solution {
public:
    unordered_map<int, int> at;
    TreeNode* buildTree(vector<int>& I, vector<int>& P) {
        for (int i = 0; i < I.size(); i++) at[I[i]]=i;
        int p = P.size()-1;
        return dfs(I, P, p, 0, I.size()-1);
    }

    TreeNode* dfs(vector<int>& I, vector<int>& P, int &p, int st, int ed) {
        if (p < 0 || at[P[p]] < st || at[P[p]] > ed) return nullptr;
        auto n = new TreeNode(P[p]);
        p--;

        n->right = dfs(I, P, p, at[n->val]+1, ed);
        n->left = dfs(I, P, p, st, at[n->val]-1);
        return n;
    }
};
