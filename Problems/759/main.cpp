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
        auto ts = vector<pair<int, int>>();

        for (auto &e : schedule)
            for (auto &i : e)
            {
                // 小細節，這邊需要反過來，sort 才會把 start 排在 end 前面
                ts.push_back({i.start, -1});
                ts.push_back({i.end, 1});
            }

        sort(ts.begin(), ts.end());
        vector<Interval> res;
        int cur = 0, last = -1, st = -1;
        for (auto &t : ts)
        {
            cur -= t.second;
            if (cur == 1 && last == 0)
                res.push_back(Interval(st, t.first));
            else if (cur == 0 && last == 1)
                st = t.first;
            last = cur;
        }

        return res;
    }
};

// 數量不多 覺得可以用 time stamp 處理比較快
