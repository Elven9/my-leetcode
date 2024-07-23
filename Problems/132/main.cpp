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
    int minCut(string s)
    {
        int n = s.size();
        // palindrome dp
        auto isPal = vector<vector<bool>>(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++)
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    if (i + 1 == j || i == j)
                        isPal[i][j] = true;
                    else
                        isPal[i][j] = isPal[i + 1][j - 1];
                }
            }

        // check min cut
        auto dp = vector<int>(n + 1, INT_MAX / 2);

        dp[0] = -1;
        for (int i = 0; i < n; i++)
            for (int j = i; j >= 0; j--)
            {
                if (!isPal[j][i])
                    continue;
                dp[i + 1] = min(dp[i + 1], dp[j] + 1);
            }

        return dp[n];
    }
};

// dp I -> solve palindrome
// dp II -> solve min cut (0:i)
