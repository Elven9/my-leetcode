#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minDistance(string A, string B)
    {
        int n = A.size(), m = B.size();
        A = "@" + A;
        B = "@" + B;

        auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
            dp[i][0] = i;
        for (int j = 1; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;

        return dp[n][m];
    }
};

// dp[i][j]: the minimum number of steps required to make word1[0:i] and word2[0:j] the same.

// if (A[i] == B[j]) dp[i][j] = dp[i-1][j-1];
// else
//     dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
