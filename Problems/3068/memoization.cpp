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
    vector<vector<long long>> dp;
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        dp = vector<vector<long long>>(nums.size(), vector<long long>(2, -1));
        return brute(nums, k, 0, 1);
    }

    long long brute(vector<int> &nums, int &k, int idx, int isPair)
    {

        if (idx == nums.size())
        {
            return !isPair ? INT_MIN : 0;
        }

        if (dp[idx][isPair] != -1)
            return dp[idx][isPair];

        long long change = (nums[idx] ^ k) + brute(nums, k, idx + 1, isPair ^ 1);
        long long noChange = nums[idx] + brute(nums, k, idx + 1, isPair);

        return dp[idx][isPair] = max(change, noChange);
    }
};
