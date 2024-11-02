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
    int res = 1;
    int maxUniqueSplit(string s)
    {
        unordered_set<string> SET;
        dfs(s, 0, SET);
        return res;
    }

    void dfs(string &s, int st, unordered_set<string> &SET)
    {
        int n = s.size();

        if (st == n)
        {
            res = max(res, int(SET.size()));
            return;
        }

        for (int i = st; i < n; i++)
        {
            string tmp = s.substr(st, i - st + 1);
            if (SET.find(tmp) == SET.end())
            {
                SET.insert(tmp);
                dfs(s, i + 1, SET);
                SET.erase(tmp);
            }
        }
    }
};
