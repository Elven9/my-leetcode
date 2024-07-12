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
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int n = dungeon.size(), m = dungeon[0].size();
        auto dp = vector<vector<int>>(n, vector<int>(m, 1));

        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == m - 1)
                    dp[i][j] = 1;
                else if (i == n - 1)
                    dp[i][j] = dp[i][j + 1] - dungeon[i][j + 1];
                else if (j == m - 1)
                    dp[i][j] = dp[i + 1][j] - dungeon[i + 1][j];
                else
                    dp[i][j] = min(dp[i][j + 1] - dungeon[i][j + 1], dp[i + 1][j] - dungeon[i + 1][j]);

                dp[i][j] = max(dp[i][j], 1);
            }

        dp[0][0] -= dungeon[0][0];
        dp[0][0] = max(dp[0][0], 1);

        return dp[0][0];
    }
};

// find a maxima path sum that can reach button right corner
// dp[i][j] from i, j to button right
