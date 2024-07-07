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
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1); // LIS end at nums[i]
        vector<int> sols(n, 0);

        // calc
        for (int i = 0; i < n; i++)
        {
            int best = 1, cnt = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] >= nums[i])
                    continue;
                if (dp[j] + 1 > best)
                {
                    best = dp[j] + 1;
                    cnt = sols[j];
                }
                else if (dp[j] + 1 == best)
                {
                    cnt += sols[j];
                }
            }
            dp[i] = best;
            sols[i] = cnt;
        }

        // gen ans
        int best = -1, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > best)
            {
                ans = sols[i];
                best = dp[i];
            }
            else if (dp[i] == best)
            {
                ans += sols[i];
            }
        }

        return ans;
    }
};
