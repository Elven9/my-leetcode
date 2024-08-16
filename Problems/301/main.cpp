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
    vector<string> res;
    // maxLen to make sure that the result will be a list of
    // unique strings that are valid with the minimum number of removals.
    int maxLen;
    vector<string> removeInvalidParentheses(string s)
    {
        // lc. 921
        int remove = 0, cnt = 0;
        for (auto c : s)
        {
            if (c == '(')
                cnt++;
            else if (c == ')')
                cnt--;
            if (cnt < 0)
            {
                remove++;
                cnt = 0;
            }
        }
        maxLen = s.size() - remove - cnt;

        dfs(s, 0, 0, "");
        return res;
    }

    void dfs(string &s, int st, int cnt, string comb)
    {
        // stop
        if (st == s.size())
        {
            if (cnt == 0 && comb.size() == maxLen)
                res.push_back(comb);
            return;
        }
        // prune
        if (cnt < 0)
            return;
        if (comb.size() > maxLen)
            return;

        // traverse
        if (s[st] != ')' && s[st] != '(')
        {
            dfs(s, st + 1, cnt, comb + s[st]);
            return;
        }

        if (comb.size() == 0 || s[st] != comb.back())
            dfs(s, st + 1, cnt, comb);
        dfs(s, st + 1, cnt + (s[st] == ')' ? -1 : 1), comb + s[st]);
    }
};
