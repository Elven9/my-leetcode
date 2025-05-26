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

class Interval
{
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end)
    {
        start = _start;
        end = _end;
    }
};

class Solution
{
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
    {
        vector<pair<int, int>> ts;

        for (auto &w : schedule)
            for (auto &i : w)
            {
                ts.push_back({i.start, -1});
                ts.push_back({i.end, 1});
            }

        int n = ts.size();
        sort(ts.begin(), ts.end());

        int idx = 0;
        vector<Interval> res;
        while (idx < n)
        {
            int st, cnt = -ts[idx++].second;
            while (idx < n && cnt != 0)
            {
                st = ts[idx].first;
                cnt -= ts[idx++].second;
            }
            if (idx < n)
            {
                res.push_back(Interval(st, ts[idx].first));
            }
        }
        return res;
    }
};
