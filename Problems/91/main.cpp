#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();

        s = "@" + s;
        auto dp = vector<int>(n + 1, 0);

        dp[0] = 1;
        dp[1] = isValid(s.substr(1, 1)) ? 1 : 0;
        for (int i = 2; i <= n; i++)
        {
            if (isValid(s.substr(i, 1)))
                dp[i] += dp[i - 1];
            if (isValid(s.substr(i - 1, 2)))
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }

    bool isValid(string s)
    {
        int num = stoi(s);
        return s[0] != '0' && num > 0 && num <= 26;
    }
};

// dp[i]: he number of ways to decode s[0:i]

// dp[i] = dp[i-1] + (isValid(s.substr(i-1, 2)) ? dp[i-2] : 0);
