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

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> q;

        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto n = q.front();
                q.pop();
                n->next = len == 0 ? nullptr : q.front();
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
        }

        return root;
    }
};
