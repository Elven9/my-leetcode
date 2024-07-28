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

using LL = long long;

class Solution
{
public:
    LL mod = 1e9 + 7;
    int distinctSubseqII(string s)
    {
        int n = s.size();
        auto dp = vector<LL>(n + 1, 0);
        auto last = vector<int>(26, 0);
        s = "#" + s;

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int j = last[s[i] - 'a'];

            if (j != 0)
                dp[i] = (dp[i - 1] * 2 - dp[j - 1]) % mod;
            else
                dp[i] = (dp[i - 1] * 2) % mod;

            last[s[i] - 'a'] = i;
        }

        // need to remove empty sequence
        return (dp[n] - 1 + mod) % mod;
    }
};

// [X X X X] X X j X X i
// construct sequence
// remove same sequence

// dp[i]: distinct non-empty subsequences of s[0:i]

// dp[i] = dp[i-1]*2 - dp[j-1]
