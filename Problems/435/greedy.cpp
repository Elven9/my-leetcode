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
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) -> bool
             { return a[1] < b[1]; });

        int res = 0, i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && intervals[j][0] < intervals[i][1])
                j++;
            res += j - i - 1;
            i = j;
        }

        return res;
    }
};

// 1, 2
// 2, 3
// 3, 4
// 4, 5
// 1, 7

// 如果後面的 interval 跟前面某個已經決定的 interval 有 overlap，那他一定會跟上一個 interval overlap ( sort by ending 的原因 )
