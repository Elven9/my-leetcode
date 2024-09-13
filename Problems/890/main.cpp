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
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        int n = pattern.size();
        vector<string> res;
        for (auto &w : words)
        {
            vector<char> MAP(26, 0);
            bool ok = true;
            for (int i = 0; i < n; i++)
            {
                char c = w[i], p = pattern[i];
                if (MAP[p - 'a'] != 0)
                {
                    if (MAP[p - 'a'] != c)
                    {
                        ok = false;
                        break;
                    }
                }
                else
                {
                    if (find(MAP.begin(), MAP.end(), c) != MAP.end())
                    {
                        ok = false;
                        break;
                    }
                    MAP[p - 'a'] = c;
                }
            }
            if (ok)
                res.push_back(w);
        }

        return res;
    }
};
