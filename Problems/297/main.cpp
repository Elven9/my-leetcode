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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // parse
        vector<TreeNode *> tokens;
        int pos = 0;
        while (true)
        {
            int next = data.find(",", pos);
            string tmp = data.substr(pos, next - pos);
            if (tmp == "#")
                tokens.push_back(nullptr);
            else
                tokens.push_back(new TreeNode(stoi(tmp)));
            if (next == string::npos)
                break;
            pos = next + 1;
        }

        auto root = tokens[0];
        stack<TreeNode *> st;
        int idx = 1;

        // preorder traversal !!!
        while ((!st.empty() || root) && idx < tokens.size())
        {
            if (root)
            {
                st.push(root);
                root->left = tokens[idx++];
                root = root->left;
            }
            else
            {
                auto n = st.top();
                st.pop();
                n->right = tokens[idx++];
                root = n->right;
            }
        }

        return tokens[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
