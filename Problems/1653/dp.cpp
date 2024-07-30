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
    int minimumDeletions(string s)
    {
        int n = s.size();
        s = "@" + s;

        int b = 0;
        auto dp = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 'b')
            {
                dp[i] = dp[i - 1];
                b++;
            }
            else
                dp[i] = min(dp[i - 1] + 1, b);
        }

        return dp[n];
    }
};

// dp[i] ->  minimum number of deletions needed to make s[0:i] balanced

// if (s[i] == 'a')
//     dp[i] = min(dp[i-1]+1, b[i]);
