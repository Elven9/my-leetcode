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
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        s = "#" + s;

        auto dp = vector<bool>(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
            for (auto &w : wordDict)
            {
                int j = i - w.size();
                if (j < 0)
                    continue;
                dp[i] = dp[i] || (dp[j] && (w == s.substr(j + 1, w.size())));
            }

        return dp[n];
    }
};
