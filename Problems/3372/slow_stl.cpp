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

struct Node
{
    vector<int> next;
    int val;
    int idx;
};

class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<Node> t1(n);
        vector<Node> t2(m);

        for (int i = 0; i < n; i++)
            t1[i].idx = i;
        for (int i = 0; i < m; i++)
            t2[i].idx = i;

        for (auto &e : edges1)
        {
            t1[e[0]].next.push_back(e[1]);
            t1[e[1]].next.push_back(e[0]);
        }
        for (auto &e : edges2)
        {
            t2[e[0]].next.push_back(e[1]);
            t2[e[1]].next.push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
            t1[i].val = cal(t1, i, k);
        for (int i = 0; i < m; i++)
            t2[i].val = cal(t2, i, k - 1);

        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            int tmp = INT_MIN;
            for (int j = 0; j < m; j++)
                tmp = max(tmp, t2[j].val);
            res[i] = t1[i].val + tmp;
        }

        return res;
    }

    int cal(vector<Node> &tree, int st, int k)
    {
        queue<Node *> q;
        unordered_map<int, bool> visited;
        q.push(&tree[st]);
        visited[st] = true;

        int res = 0;
        while (!q.empty() && k >= 0)
        {
            int len = q.size();
            res += len;
            while (len-- > 0)
            {
                Node *t = q.front();
                q.pop();

                for (auto &c : t->next)
                {
                    if (c == t->idx || visited[c])
                        continue;
                    q.push(&tree[c]);
                    visited[c] = true;
                }
            }
            k--;
        }

        return res;
    }
};

// BFS on each node to find k lenght path (好險是 tree，不用用那些 shortest path)
