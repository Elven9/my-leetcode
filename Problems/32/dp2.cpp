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

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        s = "@" + s;

        auto dp = vector<int>(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '(')
            {
                dp[i] = 0;
                continue;
            }
            int j = i - 1, st = 1;

            while (j >= 1 && st != 0)
                st += s[j--] == ')' ? 1 : -1;

            if (st == 0)
                dp[i] = dp[j] + i - j;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

// dp[i]: the length of the longest valid (well-formed) parentheses substring end at s[i]

// dp[i] = valid substring + dp[j]
