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
        sort(intervals.begin(), intervals.end());

        intervals.insert(intervals.begin(), {INT_MIN, INT_MIN});
        int dp[n + 1];

        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int j = i - 1;
            while (!(intervals[j][1] <= intervals[i][0]))
                j--;
            dp[i] = min(dp[i - 1] + 1, dp[j] + i - j - 1);
        }

        return dp[n];
    }
};

// sort interval

// dp[i]:  minimum number of intervals you need to remove to make intervals[0:i] to make the rest of the intervals[0:i] non-overlapping

// dp[i]=min(dp[i-1]+1, dp[j]+i-j-1)

// may TLE
