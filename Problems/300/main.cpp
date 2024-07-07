#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                dp[i] = max(dp[i], nums[i] > nums[j] ? dp[j] + 1 : -1);

        return *max_element(dp.begin(), dp.end());
    }
};
