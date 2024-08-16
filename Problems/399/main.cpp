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
    vector<double> res;
    vector<double> calcEquation(vector<vector<string>> &E, vector<double> &V, vector<vector<string>> &Q)
    {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < E.size(); i++)
        {
            graph[E[i][0]].push_back({E[i][1], V[i]});
            graph[E[i][1]].push_back({E[i][0], 1.0 / V[i]});
        }

        for (auto q : Q)
        {
            unordered_set<string> visited;
            if (!dfs(graph, visited, 1.0, q[0], q[1]))
                res.push_back(-1.0);
        }

        return res;
    }

    bool dfs(unordered_map<string, vector<pair<string, double>>> &graph, unordered_set<string> &visited, double v, string st, string ed)
    {
        if (st == ed && !(graph[st].size() == 0 && graph[ed].size() == 0))
        {
            res.push_back(v);
            return true;
        }

        if (visited.find(st) != visited.end())
            return false;
        visited.insert(st);

        auto E = graph[st];
        bool ok = false;
        for (auto e : E)
        {
            ok = dfs(graph, visited, v * e.second, e.first, ed);
            if (ok)
                return true;
        }
        return false;
    }
};
