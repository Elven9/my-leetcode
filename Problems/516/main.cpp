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
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        s = "#" + s;

        auto dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

        for (int i = 1; i <= n; i++)
            dp[i][i] = 1;

        for (int len = 2; len <= n; len++)
            for (int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;

                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }

        return dp[1][n];
    }
};

// X X X i [X X X X] j
