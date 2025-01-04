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
        vector<int> st(26, INT_MAX);
        vector<int> ed(26, INT_MAX);

        for (int i = 0; i < n; i++)
        {
            st[s[i] - 'a'] = min(st[s[i] - 'a'], i);
            ed[s[i] - 'a'] = i;
        }

        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (st[i] == INT_MAX || st[i] == ed[i])
                continue;

            res += unordered_set<char>(s.begin() + st[i] + 1, s.begin() + ed[i]).size();
        }
        return res;
    }
};

// find unique between
