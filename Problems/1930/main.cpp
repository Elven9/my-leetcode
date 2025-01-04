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
    int countPalindromicSubsequence(string s)
    {
        int n = s.size();
        s = '#' + s;
        vector<vector<int>> prefix(1, vector<int>(26, 0));

        for (int i = 1; i <= n; i++)
        {
            prefix.push_back(prefix.back());
            prefix.back()[s[i] - 'a']++;
        }

        vector<int> st(26, -1);
        vector<int> ed(26, -1);

        for (int i = 1; i <= n; i++)
            if (st[s[i] - 'a'] == -1)
                st[s[i] - 'a'] = i;

        for (int i = n; i > 0; i--)
            if (ed[s[i] - 'a'] == -1)
                ed[s[i] - 'a'] = i;

        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (st[i] == ed[i] || st[i] == ed[i] + 1)
                continue;

            for (int j = 0; j < 26; j++)
            {
                res += (prefix[ed[i] - 1][j] - prefix[st[i]][j] > 0);
            }
        }

        return res;
    }
};

// 區間 unique count
