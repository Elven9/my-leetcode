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
    short memo[31][31][31] = {0};
    string a, b;
    bool isScramble(string s1, string s2)
    {
        a = s1;
        b = s2;

        return dfs(0, 0, a.size());
    }

    bool dfs(int st, int t, int len)
    {
        if (memo[st][t][len] != 0)
            return memo[st][t][len] == 1;
        if (len == 1)
        {
            memo[st][t][len] = a[st] == b[t] ? 1 : 2;
            return a[st] == b[t];
        }

        if (a.substr(st, len) == b.substr(t, len))
        {
            memo[st][t][len] = 1;
            return true;
        }

        for (int i = 1; i < len; i++)
        {
            if (dfs(st, t, i) && dfs(st + i, t + i, len - i))
            {
                memo[st][t][len] = 1;
                return true;
            }
            if (dfs(st, t + len - i, i) && dfs(st + i, t, len - i))
            {
                memo[st][t][len] = 1;
                return true;
            }
        }

        memo[st][t][len] = 2;
        return false;
    }
};

// g r eat

// r g eat

// g r
// r g
