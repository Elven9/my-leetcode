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
    int findMaxForm(vector<string> &strs, int M, int N)
    {
        auto dp = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));

        for (int i = 0; i < strs.size(); i++)
        {
            int cnt[2] = {0, 0};
            for (auto &c : strs[i])
                cnt[c - '0']++;

            auto dp2 = dp;

            for (int m = 0; m <= M; m++)
                for (int n = 0; n <= N; n++)
                    dp[m][n] = max(dp2[m][n], (m - cnt[0] < 0 || n - cnt[1] < 0) ? INT_MIN : dp2[m - cnt[0]][n - cnt[1]] + 1);
        }

        return max(dp[M][N], 0);
    }
};

// X X X X X X i
// select or not select -> dp[i]
// select state *at most* m, n, so default dp will no be populated with INT_MIN
