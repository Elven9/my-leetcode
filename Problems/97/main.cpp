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
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size())
            return false;

        s1 = "@" + s1;
        s2 = "@" + s2;
        s3 = "@" + s3;
        auto dp = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
            dp[i][0] = s1[i] == s3[i] && dp[i - 1][0];

        for (int i = 1; i <= m; i++)
            dp[0][i] = s2[i] == s3[i] && dp[0][i - 1];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = s1[i] == s3[i + j] && dp[i - 1][j];
                dp[i][j] = dp[i][j] || (s2[j] == s3[i + j] && dp[i][j - 1]);
            }

        return dp[n][m];
    }
};

// [X X X X X X] i

// len(s1)+len(s2) == len(s3)

// dp[i][j]: whether s3[0:i+j] is formed by an interleaving of s1[0:i], s2[0:j]

// s1[i] == s3[i]
