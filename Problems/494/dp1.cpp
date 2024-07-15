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
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0) + abs(target);
        if (sum % 2 == 1)
            return 0;

        int n = nums.size();
        auto dp = vector<int>(sum / 2 + 1, 0);

        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            auto dp2 = dp;
            for (int s = 0; s <= sum / 2; s++)
            {
                dp[s] = dp2[s] + (s - nums[i] >= 0 ? dp2[s - nums[i]] : 0);
            }
        }

        return dp[sum / 2];
    }
};

// select or not select
// combination to sum/2
