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
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        auto dp = vector<bool>(n, false);
        dp[0] = true;

        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
            {
                dp[i] = dp[j] && nums[j] >= (i - j);
                if (dp[i])
                    break;
            }

        return dp[n - 1];
    }
};

// DP
// dp[i]: where the person can reach i index
// dp[i] = [dp[i-1] && nums[i-k] >= k] for k < i
