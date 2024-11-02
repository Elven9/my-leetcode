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
    int dp[1000][1000];
    int maxMoves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        for (int i = 0; i < 1000; i++)
            for (int j = 0; j < 1000; j++)
                dp[i][j] = -1;

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            res = max(res, dfs(grid, i, 0));
        }
        return res;
    }

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = -1;
        if (i - 1 >= 0 && j + 1 < n && grid[i][j] < grid[i - 1][j + 1])
            res = max(res, dfs(grid, i - 1, j + 1));
        if (j + 1 < n && grid[i][j] < grid[i][j + 1])
            res = max(res, dfs(grid, i, j + 1));
        if (i + 1 < m && j + 1 < n && grid[i][j] < grid[i + 1][j + 1])
            res = max(res, dfs(grid, i + 1, j + 1));

        dp[i][j] = res + 1;
        return res + 1;
    }
};

//     a
// -   a
//     a
