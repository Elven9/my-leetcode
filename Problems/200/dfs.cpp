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
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, visited);
                    res++;
                }

        return res;
    }

    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int m = i + dir[k][0], n = j + dir[k][1];
            if (m < 0 || m >= grid.size() || n < 0 || n >= grid[0].size())
                continue;
            if (visited[m][n])
                continue;
            if (grid[m][n] == '0')
                continue;

            dfs(grid, m, n, visited);
        }
    }
};
