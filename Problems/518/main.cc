#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        // Backtracking -> 2D DP -> 1D DP
        // i -> amount

        int dp[amount + 1];
        for (int i = 0; i < amount + 1; i++)
        {
            dp[i] = 0;
        }
        dp[0] = 1;

        for (int c : coins)
        {
            for (int i = c; i <= amount; i++)
            {
                dp[i] += dp[i - c];
            }
        }

        return dp[amount];
    }
};
