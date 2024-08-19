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
    int splitArray(vector<int> &nums, int K)
    {
        int n = nums.size();
        if (K == n)
            return *max_element(nums.begin(), nums.end());

        auto dp = vector<vector<int>>(n + 1, vector<int>(K + 1, INT_MAX));
        nums.insert(nums.begin(), 0);

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= min(K, i); k++)
            {
                int sum = 0;

                for (int j = i; j >= 1; j--)
                {
                    sum += nums[j];
                    dp[i][k] = min(dp[i][k], max(dp[j - 1][k - 1], sum));
                }
            }

        return dp[n][K];
    }
};

// [X X X X j] (X X X i) -> sum

// dp[i][k] = min(dp[i][k], max(dp[j][k-1], sum));

// [j] (X X X X X X X i) , k = 1
