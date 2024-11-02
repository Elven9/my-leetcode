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
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        grid.insert(grid.begin(), vector<int>(n, 1));
        for (auto &r : grid)
            r.insert(r.begin(), 1);

        grid[0][1] = 0;

        auto dp = vector<vector<long>>(m + 1, vector<long>(n + 1, 0));
        dp[0][1] = 1;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                dp[i][j] += grid[i - 1][j] == 1 ? 0 : dp[i - 1][j];
                dp[i][j] += grid[i][j - 1] == 1 ? 0 : dp[i][j - 1];
            }

        return dp[m][n];
    }
};
