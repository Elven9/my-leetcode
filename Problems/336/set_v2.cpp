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
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();
        unordered_map<string, int> MAP;

        for (int i = 0; i < n; i++)
            MAP[words[i]] = i;

        // 用來去重複 result 的
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.size() < b.size(); });

        unordered_set<string> SET;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            string &w = words[i];

            for (int j = 0; j <= w.size(); j++)
            {
                if (check(w, 0, j - 1))
                {
                    string tmp = w.substr(j);
                    reverse(tmp.begin(), tmp.end());
                    if (SET.find(tmp) != SET.end())
                        res.push_back({MAP[tmp], MAP[w]});
                }
                if (check(w, j, w.size() - 1))
                {
                    string tmp = w.substr(0, j);
                    reverse(tmp.begin(), tmp.end());
                    if (SET.find(tmp) != SET.end())
                        res.push_back({MAP[w], MAP[tmp]});
                }
            }

            SET.insert(w);
        }

        return res;
    }

    bool check(string &s, int st, int ed)
    {
        while (st < ed)
        {
            if (s[st] != s[ed])
                return false;
            st++;
            ed--;
        }
        return true;
    }
};