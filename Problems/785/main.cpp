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
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        auto colors = vector<int>(n, 0);

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (colors[i] != 0)
                continue;

            q.push(i);
            colors[i] = 2;

            while (!q.empty())
            {
                int len = q.size();
                while (len-- > 0)
                {
                    for (auto &node : graph[q.front()])
                    {
                        if (colors[node] == colors[q.front()])
                            return false;
                        if (colors[node] != 0)
                            continue;
                        q.push(node);
                        colors[node] = colors[q.front()] ^ 1;
                    }
                }
                q.pop();
            }
        }

        return true;
    }
};

// bfs bypartite 塗色
