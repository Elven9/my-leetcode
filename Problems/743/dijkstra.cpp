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
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto &t : times)
            graph[t[0]].push_back({t[1], t[2]});

        int res = 0;
        vector<bool> visited(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [time, node] = pq.top();
            pq.pop();

            if (visited[node])
                continue;
            visited[node] = true;
            res = max(res, time);

            for (auto &[next, w] : graph[node])
            {
                if (visited[next])
                    continue;
                pq.push({time + w, next});
            }
        }

        for (int i = 1; i <= n; i++)
            if (!visited[i])
                return -1;
        return res;
    }
};
