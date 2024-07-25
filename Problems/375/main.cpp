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
    int getMoneyAmount(int n)
    {
        auto dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n; len++)
            for (int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k <= j; k++)
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
            }

        return dp[1][n];
    }
};

// dfs(1, n)

// res = INT_MAX
// for k=1:n
//     res = min(res, k+max(dfs(1, k-1), dfs(k+1, n)))

// optimization by memoization

// button up building, decision transformation from smaller segment
