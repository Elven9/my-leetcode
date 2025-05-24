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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.rbegin(), intervals.rend());

        vector<vector<int>> res;
        do
        {
            int st = intervals.back()[0], ed = intervals.back()[1];
            intervals.pop_back();
            while (intervals.size() > 0 && intervals.back()[0] <= ed)
            {
                ed = max(ed, intervals.back()[1]);
                intervals.pop_back();
            }
            res.push_back({st, ed});
        } while (intervals.size() > 0);

        return res;
    }
};
