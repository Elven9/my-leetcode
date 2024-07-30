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
    int jump(vector<int> &nums)
    {
        int n = nums.size();

        auto dp = vector<int>(n, INT_MAX / 2);

        dp[0] = 0;
        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                dp[i] = min(dp[i], nums[j] >= (i - j) ? dp[j] + 1 : INT_MAX);

        return dp[n - 1];
    }
};

// dp[i]: minimum number of jumps to reach i
// dp[i] = min(dp[i], dp[j] ....)
