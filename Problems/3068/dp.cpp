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
        int n = nums.size();
        nums.insert(nums.begin(), -1);
        auto dp = vector<vector<long long>>(n + 1, vector<long long>(2, 0));
        // 0 -> need one more change to be valid
        // 1 -> change should be paired up
        dp[0][0] = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][1] + (nums[i] ^ k), dp[i - 1][0] + nums[i]);
            dp[i][1] = max(dp[i - 1][0] + (nums[i] ^ k), dp[i - 1][1] + nums[i]);
        }
        return dp[n][1];
    }
};

// dp[i][j]: when using i node, max value that can be achieve when pair up all change or need one more change
// 問題拆分成
// valid 狀態 => max(「這次改 + 之前缺一改」,「這次不改 + 之前已經 pair 改」)
// 不 valid 一樣也要計算狀態，代表的是現在還不 valid 的感覺
//
// 這兩個都考慮完 solution space 就完整了
