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

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> backward(n);
        vector<int> outDeg(n, 0);

        for (int i = 0; i < n; i++)
        {
            outDeg[i] = graph[i].size();
            for (auto &next : graph[i])
                backward[next].push_back(i);
        }

        vector<int> res;
        vector<bool> visited(n, false);
        queue<int> q;

        for (int i = 0; i < n; i++)
            if (outDeg[i] == 0)
            {
                visited[i] = true;
                res.push_back(i);
                q.push(i);
            }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &next : backward[node])
            {
                if (visited[next])
                    continue;
                outDeg[next]--;
                if (outDeg[next] == 0)
                {
                    visited[next] = true;
                    res.push_back(next);
                    q.push(next);
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
