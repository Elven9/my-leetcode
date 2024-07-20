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
    long mod = 1e9 + 7;
    int dp[105][105][105];
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {

        dp[0][0][0] = 1;

        int m = group.size();
        group.insert(group.begin(), 0);
        profit.insert(profit.begin(), 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j <= n; j++)
                for (int p = 0; p <= minProfit; p++)
                {
                    dp[i + 1][j][p] += dp[i][j][p];
                    dp[i + 1][j][p] %= mod;

                    if (j + group[i + 1] <= n)
                    {
                        dp[i + 1][j + group[i + 1]][min(minProfit, p + profit[i + 1])] += dp[i][j][p];
                        dp[i + 1][j + group[i + 1]][min(minProfit, p + profit[i + 1])] %= mod;
                    }
                }

        int ret = 0;
        for (int i = 0; i <= n; i++)
            ret = (ret + dp[m][i][minProfit]) % mod;
        return ret;
    }
};

// dfs, select or not select ( 2^n )
// if profit < minProfit && n == 0 -> return 0
// if profit > min Profit -> return 1

// dp[i][n][profit] = dp[i-1][n-group[i]][profit-profit[i]] + dp[i-1][n][profit]

// Two point !

// reverse dp formula
// cap minProfit to prevent space, time to large
