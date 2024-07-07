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
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }

        int idx = 0, best = -1;
        for (int i = 0; i < dp.size(); i++)
            if (dp[i] > best)
            {
                best = dp[i];
                idx = i;
            }

        vector<int> ret;
        while (idx != -1)
        {
            ret.push_back(nums[idx]);
            idx = prev[idx];
        }

        return ret;
    }
};
