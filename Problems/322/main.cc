#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // Initial Backtracking Solution
        // Generate every combination and get the minimum count of combination

        // So Let's change to 2D DP solution to avoid redundant calculation
        // i -> coins kind
        // j -> amount
        // dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]]+1)

        int n = coins.size();
        int m = amount;
        int dp[n + 1][m + 1];

        for (int j = 0; j <= m; j++)
            dp[0][j] = -1; // Meaning Can't be Done

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0; // Automatically Done

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = min(
                    dp[i - 1][j] == -1 ? INT_MAX : dp[i - 1][j],
                    j >= coins[i - 1] && dp[i][j - coins[i - 1]] != -1 ? dp[i][j - coins[i - 1]] + 1 : INT_MAX);
                if (dp[i][j] == INT_MAX)
                    dp[i][j] = -1;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << setw(4) << dp[i][j];
            }
            cout << endl;
        }

        return dp[n][m];
    }
};

int main()
{
    vector<int> coins{1, 2, 5};
    Solution sol;
    sol.coinChange(coins, 11);

    return 0;
}
