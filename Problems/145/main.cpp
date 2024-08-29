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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st;

        vector<int> res;
        while (!st.empty() || root != nullptr)
        {
            if (!root)
            {
                int state = st.top().second;
                root = st.top().first;
                st.pop();

                if (state == 0)
                {
                    st.push({root, state + 1});
                    root = root->right;
                }
                else if (state == 1)
                {
                    res.push_back(root->val);
                    root = nullptr;
                }
            }
            else
            {
                st.push({root, 0});
                root = root->left;
            }
        }
        return res;
    }
};
