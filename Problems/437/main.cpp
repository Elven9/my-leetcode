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

using LL = long long;
class Solution
{
public:
    int res = 0;
    unordered_map<LL, int> freq;
    int pathSum(TreeNode *root, int targetSum)
    {
        freq[0] = 1;
        dfs(root, 0, targetSum);
        return res;
    }

    void dfs(TreeNode *root, LL sum, int &T)
    {
        if (!root)
            return;

        sum += root->val;
        res += freq[sum - T]; // memory may consume too much Q
        freq[sum]++;
        dfs(root->left, sum, T);
        dfs(root->right, sum, T);
        freq[sum]--;
    }
};

// dfs + prefix sum + hash table
