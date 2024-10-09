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

        set<pair<int, int>> res;
        for (int i = 0; i < n; i++)
        {
            string w = words[i];

            for (int j = 0; j <= w.size(); j++)
            {
                string w1 = w.substr(0, j); // can be optimized
                string w2 = w.substr(j);    // can be optimized

                if (check(w1))
                {
                    string tmp = w2;
                    reverse(tmp.begin(), tmp.end());
                    if (MAP.find(tmp) != MAP.end() && MAP[tmp] != i)
                        res.insert({MAP[tmp], i});
                }
                if (check(w2))
                {
                    string tmp = w1;
                    reverse(tmp.begin(), tmp.end());
                    if (MAP.find(tmp) != MAP.end() && MAP[tmp] != i)
                        res.insert({i, MAP[tmp]});
                }
            }
        }

        vector<vector<int>> _res;
        for (auto &[v1, v2] : res)
            _res.push_back({v1, v2});
        return _res;
    }

    bool check(string &s)
    // can be optimized
    {
        int st = 0, ed = s.size() - 1;
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
