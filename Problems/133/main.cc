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

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloned[105] = {nullptr};
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        if (cloned[node->val])
            return cloned[node->val];

        Node *clone = new Node(node->val);
        cloned[clone->val] = clone;

        for (auto n : node->neighbors)
            clone->neighbors.push_back(cloneGraph(n));

        return clone;
    }
};
