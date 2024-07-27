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

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int LEN = min(m, n);

        auto dp = vector<vector<bool>>(m, vector<bool>(n, false));

        int best = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = matrix[i][j] == '1';
                if (matrix[i][j] == '1')
                    best = 1;
            }

        for (int len = 2; len <= LEN; len++)
            for (int i = 0; i <= m - len; i++)
                for (int j = 0; j <= n - len; j++)
                {
                    dp[i][j] = dp[i][j] && dp[i + 1][j] && dp[i][j + 1] && dp[i + 1][j + 1];
                    if (dp[i][j] && len > best)
                        best = len;
                }

        return best * best;
    }
};

// dp[i][j][len] -> left, upper corner, w/ len area all fill with 1

// dp[300][300] => ok
