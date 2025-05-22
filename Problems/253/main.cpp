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
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<>> ends;
        int res = INT_MIN;
        for (auto &i : intervals)
        {
            while (!ends.empty() && ends.top() <= i[0])
                ends.pop();
            ends.push(i[1]);
            res = max(res, int(ends.size()));
        }
        return res;
    }
};
