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

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        auto dp = vector<unsigned int>(target + 1, 0);

        dp[0] = 1;
        for (int sum = 1; sum <= target; sum++)
            for (auto &n : nums)
                if (sum - n >= 0)
                    dp[sum] += dp[sum - n];

        return dp[target];
    }
};

// dp[i][sum]: using nums[0:i], how many combination are there that can add up to sum
