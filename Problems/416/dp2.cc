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
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;

        int n = nums.size();
        auto dp = vector<vector<bool>>(n + 1, vector<bool>(sum / 2 + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
            for (int s = 1; s <= sum / 2; s++)
                // select or not select ( build up from scratch )
                dp[i][s] = (s - nums[i - 1] >= 0 && dp[i - 1][s - nums[i - 1]]) || dp[i - 1][s];

        return dp[n][sum / 2];
    }
};
