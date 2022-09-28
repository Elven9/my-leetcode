#include <vector>
#include <iostream>
#include <string>
#include <map>

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
    int ts;
    int res;
    map<long long int, int> cache;

    int pathSum(TreeNode *root, int targetSum)
    {
        // Memoization
        // Datatype should be long long int
        ts = targetSum;
        res = 0;

        cache[0] = 1;
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, long long int curSum)
    {
        if (!root)
            return;

        curSum += root->val;
        // THIS IS WHERE THE IMPORTANT PART IS
        long long int subPath = curSum - ts;
        if (cache[subPath] != 0)
        {
            res += cache[subPath];
        }
        cache[curSum]++;

        dfs(root->left, curSum);
        dfs(root->right, curSum);
        cache[curSum]--;
    }
};

class Solution_Naive
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        // Naive solution: O(n^2), bruteforce method
        // Two level dfs and check length

        // There should be a one pass solution in O(n)
        if (root == nullptr)
            return 0;

        return dfsCheck(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int dfsCheck(TreeNode *root, long long int sum, int target)
    {
        if (root == nullptr)
            return 0;

        long long int next = sum + root->val;
        return (next == target ? 1 : 0) + dfsCheck(root->left, next, target) + dfsCheck(root->right, next, target);
    }
};
