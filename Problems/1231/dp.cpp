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
#include <cctype>

using namespace std;

// GONNA TLE
class Solution
{
public:
    int maximizeSweetness(vector<int> &S, int K)
    {
        K++;
        int n = S.size();
        S.insert(S.begin(), 0);
        auto dp = vector<vector<int>>(K + 1, vector<int>(n + 1, INT_MAX));

        for (int i = 1; i <= K; i++)
            for (int j = 1; j <= n; j++)
            {
                int sum = 0;
                dp[i][j] = INT_MIN;
                for (int k = j; k >= i; k--)
                {
                    sum += S[k];
                    // 每個產出的數值 (dp[i-1][k-1], sum) 都是 chunks 裡面 sweetness 最小值
                    // 但我們要取這些最小值裡面 (或是說這些切法) 的最大值 :)
                    dp[i][j] = max(dp[i][j], min(dp[i - 1][k - 1], sum));
                }
            }

        return dp[K][n];
    }
};

// dp[i][j]: among all i chunks of chocolate, dp[i][j] is the maximum value of all minimum of sweenetess of all cut methods of S[0:j]
