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
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> dp(k, LLONG_MAX);

        dp[k - 1] = 0;
        long long sum = 0, res = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (i >= k - 1)
                res = max(res, sum - dp[i % k]);
            dp[i % k] = min(dp[i % k], sum);
        }

        return res;
    }
};
