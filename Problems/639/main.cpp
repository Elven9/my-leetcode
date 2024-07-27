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
    int numDecodings(string s)
    {
        int n = s.size();
        auto dp = vector<LL>(n + 1, 0);

        s = "#" + s;

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '*' && s[i] == '*')
            {
                dp[i] = (dp[i] + dp[i - 2] * 15) % mod;
            }
            if (s[i] == '*')
            {
                if (s[i - 1] == '1')
                    dp[i] = (dp[i] + dp[i - 2] * 9) % mod;
                else if (s[i - 1] == '2')
                    dp[i] = (dp[i] + dp[i - 2] * 6) % mod;
                dp[i] = (dp[i] + dp[i - 1] * 9) % mod;
            }
            if (s[i - 1] == '*')
            {
                if (s[i] >= '0' && s[i] <= '9')
                    dp[i] = (dp[i] + dp[i - 2]) % mod;
                if (s[i] >= '0' && s[i] <= '6')
                    dp[i] = (dp[i] + dp[i - 2]) % mod;
            }
            if (s[i - 1] != '0' && s[i - 1] != '#' && s[i - 1] != '*' && s[i] != '*')
            {
                int num = stoi(s.substr(i - 1, 2));
                if (num >= 10 && num <= 26)
                    dp[i] = (dp[i] + dp[i - 2]) % mod;
            }
            if (s[i] >= '1' && s[i] <= '9')
            {
                dp[i] = (dp[i] + dp[i - 1]) % mod;
            }
        }
        return dp[n];
    }
};

// 1 - 26
// *1 -> 11 21 (v)
// 1* -> 11 12 .... 19 (v)
// 2* -> 21 22 .... 26 (v)
// * -> 1 2 .... 9 (v)
