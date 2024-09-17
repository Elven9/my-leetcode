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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        // stack solution is too clever
        stack<TreeNode *> st;
        for (auto &n : nums)
        {
            TreeNode *cur = nullptr;
            while (!st.empty() && st.top()->val < n)
            {
                cur = st.top();
                st.pop();
                if (!st.empty())
                    st.top()->right = cur;
            }
            st.push(new TreeNode(n));
            st.top()->left = cur;
        }

        while (st.size() > 1)
        {
            auto tmp = st.top();
            st.pop();
            st.top()->right = tmp;
        }

        return st.top();
    }
};

// simple solution => find max and build
