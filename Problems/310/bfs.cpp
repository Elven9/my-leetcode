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
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);
        vector<int> inDeg(n, 0);

        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            inDeg[e[0]]++;
            inDeg[e[1]]++;
        }

        queue<int> q;
        vector<bool> visited(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (inDeg[i] <= 1)
            {
                q.push(i);
                visited[i] = true;
                cnt++;
            }

        while (!q.empty())
        {
            if (cnt == n)
                break;
            int len = q.size();
            while (len-- > 0)
            {
                int node = q.front();
                q.pop();

                for (auto &next : graph[node])
                {
                    if (visited[next])
                        continue;
                    inDeg[next]--;
                    if (inDeg[next] <= 1)
                    {
                        visited[next] = true;
                        q.push(next);
                        cnt++;
                    }
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
