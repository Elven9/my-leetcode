#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int N = grid.size();
        int dp[N + 1][N + 1][N + 1];

        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                for (int k = 0; k <= N; k++)
                    dp[i][j][k] = INT_MIN;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                for (int x = 1; x <= N; x++)
                {
                    int y = i + j - x; // move simultaneously

                    if (y < 1 || y > N)
                        continue;
                    if (grid[i - 1][j - 1] == -1 || grid[x - 1][y - 1] == -1)
                        continue;

                    if (i == 1 && j == 1 && x == 1)
                    {
                        dp[i][j][x] = grid[i - 1][j - 1];
                        continue;
                    }

                    dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][x]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][x - 1]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j - 1][x]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j - 1][x - 1]);

                    if (i == x & j == y)
                        dp[i][j][x] += grid[i - 1][j - 1];
                    else
                        dp[i][j][x] += grid[i - 1][j - 1] + grid[x - 1][y - 1];
                }

        return max(0, dp[N][N][N]);
    }
};

// 1. can be seen as gen two "simultaneously" (x+y == i+j) path
// 2. if overlapped, can only add one cheery
// 3. dp head at certain position
