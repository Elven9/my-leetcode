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
    int maxMoves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        grid.insert(grid.begin(), vector<int>(n, -1));
        grid.push_back(vector<int>(n, -1));

        auto dp = vector<vector<int>>(m + 2, vector<int>(n, 0));

        for (int j = n - 2; j >= 0; j--)
            for (int i = 1; i <= m; i++)
            {
                if (grid[i][j] < grid[i - 1][j + 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + 1);
                if (grid[i][j] < grid[i][j + 1])
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
                if (grid[i][j] < grid[i + 1][j + 1])
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
            }

        int res = INT_MIN;
        for (int i = 1; i <= m; i++)
            res = max(res, dp[i][0]);
        return res;
    }
};
