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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> graph;

        for (auto &p : prerequisites)
            graph[p[1]].push_back(p[0]);

        unordered_map<int, int> visited;
        for (int c = 0; c < numCourses; c++)
            if (!dfs(graph, visited, c))
                return false;

        return true;
    }
    bool dfs(unordered_map<int, vector<int>> &graph, unordered_map<int, int> &visited, int node)
    {
        bool ok = true;
        for (auto &next : graph[node])
        {
            if (visited[next] == 1)
                continue;
            if (visited[next] == 2)
                return false;

            visited[next] = 2;
            ok = dfs(graph, visited, next);
            visited[next] = 1;
            if (!ok)
                break;
        }
        return ok;
    }
};
