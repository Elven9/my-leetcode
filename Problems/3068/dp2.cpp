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
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        vector<long long> dp(2, 0);
        dp[0] = INT_MIN;

        for (long long n : nums)
        {
            auto dp2 = dp;
            dp[0] = max((n ^ k) + dp2[1], n + dp2[0]);
            dp[1] = max((n ^ k) + dp2[0], n + dp2[1]);
        }

        return dp[1];
    }
};
