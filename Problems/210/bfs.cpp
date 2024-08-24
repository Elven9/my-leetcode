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
    vector<int> findOrder(int N, vector<vector<int>> &P)
    {
        // 只能用 bfs 走 topology sort
        auto graph = vector<vector<int>>(N, vector<int>(0));
        auto inDeg = vector<int>(N, 0);

        for (auto &p : P)
        {
            graph[p[1]].push_back(p[0]);
            inDeg[p[0]]++;
        }

        vector<int> res;
        queue<int> q;
        for (int i = 0; i < N; i++)
            if (inDeg[i] == 0)
            {
                q.push(i);
                res.push_back(i);
            }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &next : graph[node])
            {
                inDeg[next]--;
                if (inDeg[next] == 0)
                {
                    q.push(next);
                    res.push_back(next);
                }
            }
        }

        return res.size() == N ? res : vector<int>();
    }
};
