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

        vector<int> minTime(n + 1, INT_MAX);
        minTime[0] = INT_MIN;

        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        q.push({k, 0});
        minTime[k] = 0;
        visited.insert({k, 0});

        while (!q.empty())
        {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            for (auto &n : graph[node])
            {
                int nextNode = n.first;
                int w = n.second;

                if (visited.find({nextNode, w + time}) != visited.end())
                    continue;
                if (w + time < minTime[nextNode])
                {
                    minTime[nextNode] = w + time;
                    q.push({nextNode, minTime[nextNode]});
                    visited.insert({nextNode, minTime[nextNode]});
                }
            }
        }

        int res = INT_MIN;
        for (auto &t : minTime)
            res = max(res, t);

        return res == INT_MAX ? -1 : res;
    }
};
