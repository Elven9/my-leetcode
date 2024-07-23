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
    int tallestBillboard(vector<int> &rods)
    {
        int n = rods.size();
        int MAX = 5000;
        auto dp = vector<int>(MAX * 2 + 1, INT_MIN / 2);
        dp[MAX] = 0;

        for (auto &x : rods)
        {
            auto dp2 = dp;
            for (int b = -MAX; b <= MAX; b++)
            {
                int j = MAX + b;
                if (dp2[j] < 0)
                    continue;

                if (b + x <= MAX)
                    dp[j + x] = max(dp[j + x], dp2[j] + x);
                if (b - x >= -MAX)
                    dp[j - x] = max(dp[j - x], dp2[j]);
            }
        }
        return dp[MAX];
    }
};

// largest possible
// not only equal, but maxima equal

// X X X X X i ->
//
// Each steel support must be an equal height.

// dp[i][sum] -> end at i, check if this sum is viable or not
// dp[i][sum] = dp[i-1][sum] || dp[i-1][sum-rods[i]]

// -> 兩根以上 .. ?

// 用 diff ww left - right
// dp[i][diff];

// dp[i][diff] = dp[i-1][diff] || dp[i-1][diff + rods[i]] || dp[i-1][diff - rods[i]]
