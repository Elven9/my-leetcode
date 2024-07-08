#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int inf = 1e6;
        vector<int> dp(366, inf);
        unordered_set<int> check(days.begin(), days.end());

        dp[0] = 0;
        for (int i = 1; i <= 365; i++)
        {
            if (check.find(i) == check.end())
            {
                dp[i] = dp[i - 1];
                continue;
            }

            int a = dp[max(0, i - 1)] + costs[0];
            int b = dp[max(0, i - 7)] + costs[1];
            int c = dp[max(0, i - 30)] + costs[2];

            dp[i] = min(a, min(b, c));
        }

        return dp[365];
    }
};
