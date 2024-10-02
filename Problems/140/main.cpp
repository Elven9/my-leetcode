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
    vector<string> res;
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> segs;
        dfs(s, 0, wordDict, segs);

        return res;
    }

    void dfs(string &s, int st, vector<string> &dict, vector<string> &segs)
    {
        if (st == s.size())
        {
            // construct result
            stringstream ss;
            for (auto &w : segs)
                ss << w << " ";
            res.push_back(ss.str());
            res.back().pop_back();
            return;
        }
        for (auto &w : dict)
        {
            if (st + w.size() > s.size())
                continue;
            string seg = s.substr(st, w.size());
            if (seg != w)
                continue;
            segs.push_back(seg);
            dfs(s, st + w.size(), dict, segs);
            segs.pop_back();
        }
    }
};

// DFS problem
