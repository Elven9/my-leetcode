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
        vector<int> inDeg(numCourses, 0);

        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            inDeg[p[0]]++;
        }

        int visited = 0;
        queue<int> q;
        for (int c = 0; c < numCourses; c++)
            if (inDeg[c] == 0)
            {
                q.push(c);
                visited++;
            }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (auto &next : graph[cur])
            {
                inDeg[next]--;
                if (inDeg[next] == 0)
                {
                    q.push(next);
                    visited++;
                }
            }
        }

        return visited == numCourses;
    }
};
