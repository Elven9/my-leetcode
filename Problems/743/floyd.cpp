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
#include <sstream>
#include <set>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));

        for (auto &t : times)
            dp[t[0]][t[1]] = t[2];

        for (int i = 1; i <= n; i++)
            dp[i][i] = 0;

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

        int ret = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dp[k][i] == INT_MAX / 2)
                return -1;
            ret = max(ret, dp[k][i]);
        }
        return ret;
    }
};
