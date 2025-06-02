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
    long long distributeCandies(int n, int limit)
    {
        auto dp = vector<vector<long long>>(n + 1, vector<long long>(4, -1));
        return helper(n, limit, 3, dp);
    }
    long long helper(int n, int limit, int depth, vector<vector<long long>> &dp)
    {
        if (depth == 0)
            return n == 0;
        if (dp[n][depth] != -1)
            return dp[n][depth];
        long long res = 0;
        for (int i = 0; i <= min(n, limit); i++)
            res += helper(n - i, limit, depth - 1, dp);
        return dp[n][depth] = res;
    }
};

// dp memoization .. ?
// 1e8
