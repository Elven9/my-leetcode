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
        s = '@' + s;

        auto dp = vector<int>(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            if (s[i] == '(')
                continue;

            int j = i;
            while (s[j] == ')')
            {
                int st = 1;
                j--;

                while (j >= 1 && st != 0)
                    st += s[j--] == ')' ? 1 : -1;

                if (st == 0)
                    dp[i] = max(i - j, dp[j]);
            }
        }

        return dp[n];
    }
};

// dp[i]: length of the longest valid (well-formed) parentheses substring in s[0:i]

// scan all string for valid substring
// dp[i] = max(valid substring, dp[j])

// if (s[i] = '(')
//     dp[i] = dp[i-1];

// int j = i-1, st = 1;
// while (j >= 1 && st != 0)
//     if (s[j] == ')') st++;
//     else st--;

// if (st == 0)
//     max(dp[i], dp[j-1])
