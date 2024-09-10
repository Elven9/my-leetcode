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
    // lc. 792 簡單版
    bool isSubsequence(string s, string t)
    {
        auto tb = vector<vector<int>>(1, vector<int>(26, -1));
        int n = t.size();
        t = "#" + t;
        for (int i = n; i > 0; i--)
        {
            tb.insert(tb.begin(), tb.front());
            tb.front()[t[i] - 'a'] = i;
        }

        int cur = 0;
        for (auto &c : s)
        {
            cur = tb[cur][c - 'a'];
            if (cur == -1)
                return false;
        }
        return true;
    }
};
