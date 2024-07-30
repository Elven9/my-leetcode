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
    int longestCommonSubsequence(string A, string B)
    {
        int n = A.size(), m = B.size();

        A = '!' + A;
        B = '!' + B;
        auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));

        return dp[n][m];
    }
};

// dp[i][j]: lcs between A[0:i], B[0:j]

// if (A[i] == B[j]) dp[i][j] = dp[i-1][j-1]+1;
// else dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
