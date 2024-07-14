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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        auto dp = vector<vector<int>>(n, vector<int>(n, INT_MAX));

        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = min(dp[i][j], j == 0 ? INT_MAX : dp[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], j == n - 1 ? INT_MAX : dp[i - 1][j + 1]);

                dp[i][j] += matrix[i][j];
            }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// dp[i][j] -> minimum falling path from first row to i, j
