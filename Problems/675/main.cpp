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
    int M, N;
    int cutOffTree(vector<vector<int>> &forest)
    {
        map<int, pair<int, int>> Map;
        M = forest.size();
        N = forest[0].size();

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (forest[i][j] > 1)
                    Map[forest[i][j]] = {i, j};

        int step = 0;
        int x = 0, y = 0;
        for (auto &c : Map)
        {
            int tmp = bfs(x, y, c.second.first, c.second.second, forest);
            if (tmp == -1)
                return -1;
            step += tmp;
            x = c.second.first;
            y = c.second.second;
        }

        return step;
    }

    int bfs(int x, int y, int m, int n, vector<vector<int>> &forest)
    {
        auto visited = vector<vector<bool>>(M, vector<bool>(N, false));
        vector<pair<int, int>> dir({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});
        queue<pair<int, int>> q;

        if (x == m && y == n)
            return 0;

        int step = 0;
        q.push({x, y});
        visited[x][y] = true;

        while (!q.empty())
        {
            int len = q.size();

            while (len-- > 0)
            {
                for (int d = 0; d < 4; d++)
                {
                    x = q.front().first + dir[d].first;
                    y = q.front().second + dir[d].second;
                    if (x < 0 || x >= M || y < 0 || y >= N)
                        continue;
                    if (visited[x][y] || forest[x][y] == 0)
                        continue;
                    if (x == m && y == n)
                        return step + 1;

                    q.push({x, y});
                    visited[x][y] = true;
                }
                q.pop();
            }
            step++;
        }

        return -1;
    }
};
