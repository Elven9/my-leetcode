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
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        unordered_map<int, unordered_set<int>> graph;

        for (auto &r : routes)
        {
            for (int i = 0; i < r.size(); i++)
                for (int j = 0; j < r.size(); j++)
                    if (i != j)
                        graph[r[i]].insert(r[j]);
        }

        unordered_map<int, bool> visited;
        int step = 0;

        queue<int> q;
        q.push(source);
        visited[source] = true;
        if (source == target)
            return 0;

        while (!q.empty())
        {
            int len = q.size();

            while (len-- > 0)
            {
                for (auto &next : graph[q.front()])
                {
                    if (visited[next])
                        continue;
                    if (next == target)
                        return step + 1;
                    q.push(next);
                    visited[next] = true;
                }
                q.pop();
            }
            step++;
        }
        return -1;
    }
};
