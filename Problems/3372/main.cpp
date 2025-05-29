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

class Solution
{
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> t1(n);
        vector<vector<int>> t2(m);

        for (auto &e : edges1)
        {
            t1[e[0]].push_back(e[1]);
            t1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2)
        {
            t2[e[0]].push_back(e[1]);
            t2[e[1]].push_back(e[0]);
        }

        vector<int> res(n);
        int max_t2 = INT_MIN;
        for (int i = 0; i < m; i++)
            max_t2 = max(max_t2, cal(t2, i, k - 1));
        for (int i = 0; i < n; i++)
            res[i] = cal(t1, i, k) + max_t2;

        return res;
    }

    int cal(vector<vector<int>> &tree, int st, int k)
    {
        queue<int> q;
        vector<bool> visited(1001, false);
        q.push(st);
        visited[st] = true;

        int res = 0;
        while (!q.empty() && k >= 0)
        {
            int len = q.size();
            res += len;
            while (len-- > 0)
            {
                int t = q.front();
                q.pop();

                for (auto &c : tree[t])
                {
                    if (visited[c])
                        continue;
                    q.push(c);
                    visited[c] = true;
                }
            }
            k--;
        }

        return res;
    }
};

// BFS on each node to find k lenght path (好險是 tree，不用用那些 shortest path)
