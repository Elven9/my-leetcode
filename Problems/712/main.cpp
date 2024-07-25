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
    int minimumDeleteSum(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        s1 = "@" + s1;
        s2 = "@" + s2;

        auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] + s1[i];
        for (int j = 1; j <= m; j++)
            dp[0][j] = dp[0][j - 1] + s2[j];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s1[i] == s2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i], dp[i][j - 1] + s2[j]);

        return dp[n][m];
    }
};

// dp[i][j]: lowest ASCII sum of deleted characters to make s1[0:i] equal to s2[0:j]

// if (s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];
// else
//     dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
