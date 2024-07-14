#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        auto dp = vector<int>(amount + 1, INT_MAX);

        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (auto &c : coins)
            {
                if (i - c < 0 || dp[i - c] == INT_MAX)
                    continue;
                dp[i] = min(dp[i], dp[i - c] + 1);
            }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// Just like subarray build,
// dp[i] = minimum coins used when amount == i
// dp[i] = min(dp[i-coin[0]], dp[i-coin[0]], ...) + 1
