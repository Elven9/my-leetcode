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
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        int res = 0, ed = -1e7;
        for (auto &i : intervals)
        {
            if (i[0] < ed)
            {
                // overlapped
                res++;
                ed = min(ed, i[1]);
            }
            else
                ed = i[1];
        }

        return res;
    }
};

// if not overlapped -> dk
//
// timestamp 先處理先開始的 interval
// overlapped -> 涵蓋越遠的先 removed，只要有 overlapped 就一定要處理
