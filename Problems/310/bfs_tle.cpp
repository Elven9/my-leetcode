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

        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            visited[i][i] = true;
            q.push({i, i});
        }

        if (n == 1)
            return {0};

        vector<int> cnt(n, 1);
        while (!q.empty())
        {
            int len = q.size();

            vector<int> res;
            while (len-- > 0)
            {
                int node = q.front().first;
                int from = q.front().second;
                q.pop();

                for (auto &next : graph[node])
                {
                    if (visited[from][next])
                        continue;
                    cnt[from]++;
                    if (cnt[from] == n)
                        res.push_back(from);
                    visited[from][next] = true;
                    q.push({next, from});
                }
            }

            if (res.size() != 0)
                return res;
        }

        return vector<int>();
    }
};
