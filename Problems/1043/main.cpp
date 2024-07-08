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
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        // dp[i]: maximum value of arr[0:i] after partition

        for (int i = 1; i <= n; i++)
        {
            int MAX = -1;
            for (int j = i; j >= max(1, i - k + 1); j--)
            {
                MAX = max(MAX, arr[j - 1]);
                dp[i] = max(dp[i], MAX * (i - j + 1) + dp[j - 1]);
            }
        }

        return dp[n];
    }
};
