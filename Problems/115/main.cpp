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

using LL = long long;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        s = "@" + s;
        t = "@" + t;

        if (n < m)
            return 0;
        if (n == m)
            return s == t;

        auto dp = vector<vector<LL>>(n + 1, vector<LL>(m + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                // WTF, LLONG_MAX .. ? 63 / 65 .. ?
                if (s[i] == t[j])
                    dp[i][j] = min(LLONG_MAX / 2, dp[i - 1][j - 1] + dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }

        return dp[n][m];
    }
};

// ra
// ra

// X X X X X X i
// X X X X X j

// dp[i][j]: distinct sequense that match t[:j] in s[:i]

// if (s[i] == t[j])
// 	dp[i][j] += dp[i-1][j-1]

// 			if previous has sequense that had already matched,
// dp[i][j] += dp[i-1][j]
