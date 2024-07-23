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
    double largestSumOfAverages(vector<int> &nums, int K)
    {
        int n = nums.size();
        auto dp = vector<vector<double>>(n + 1, vector<double>(K + 1, -1e4));
        nums.insert(nums.begin(), 0);

        dp[0][0] = 0.0;
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= min(i, K); k++)
            {
                int sum = 0;
                for (int j = i; j >= 1; j--)
                {
                    sum += nums[j];
                    double avg = sum * 1.0 / (i - j + 1);
                    dp[i][k] = max(dp[i][k], dp[j - 1][k - 1] + avg);
                }
            }

        return dp[n][K];
    }
};

// dp[i][k] -> from 0 to i, partition into k set, maximum score that can achieve

// dp[i][k] = max(dp[j-1][k-1]+avg)
