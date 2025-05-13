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
#include <cctype>

using namespace std;

class Solution
{
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> grid;
    vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
    {
        grid = vector<vector<int>>(m, vector<int>(n, -1));

        vector<int> res;
        int cur = 0;
        for (auto &pos : positions)
        {
            int x = pos[0], y = pos[1];
            if (grid[x][y] != -1)
            {
                res.push_back(cur);
                continue;
            }
            grid[x][y] = x * n + y;
            cur++;

            for (auto &d : dirs)
            {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if (grid[nx][ny] == -1)
                    continue;

                if (find(nx, ny) != find(x, y))
                {
                    merge(x, y, nx, ny);
                    cur--;
                }
            }

            res.push_back(cur);
        }

        return res;
    }

    int find(int x, int y)
    {
        int n = grid[0].size();
        if (grid[x][y] != x * n + y)
        {
            int nx = grid[x][y] / n, ny = grid[x][y] % n;
            grid[x][y] = find(nx, ny);
        }
        return grid[x][y];
    }

    void merge(int x, int y, int x2, int y2)
    {
        int n = grid[0].size();
        int rx = grid[x][y] / n, ry = grid[x][y] % n;
        grid[rx][ry] = x2 * n + y2;
    }
};
