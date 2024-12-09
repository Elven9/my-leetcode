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

class Solution
{
public:
    int dp[103][103][103];
    int minArraySum(vector<int> &nums, int K, int op1, int op2)
    {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        dp[0][0][0] = 0;
        for (int i = 1; i <= n; i++)
            dp[i][0][0] = dp[i - 1][0][0] + nums[i];

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= op1; j++)
                for (int k = 0; k <= op2; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k] + nums[i];
                    if (j > 0)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k] + int(ceil(double(nums[i]) / 2.0)));
                    if (k > 0 && nums[i] >= K)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - 1] + nums[i] - K);
                    if (k > 0 && nums[i] >= K && j > 0)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - 1] + int(ceil(double(nums[i] - K) / 2.0)));
                    if (k > 0 && ceil(double(nums[i]) / 2.0) >= K && j > 0)
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - 1] + int(ceil(double(nums[i]) / 2.0)) - K);
                }

        return dp[n][op1][op2];
    }
};
