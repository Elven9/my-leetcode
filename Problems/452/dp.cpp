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
    int findMinArrowShots(vector<vector<int>> &P)
    {
        int n = P.size();
        sort(P.begin(), P.end());

        P.insert(P.begin(), {INT_MIN, INT_MIN});
        int dp[n + 1];

        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            int j = i - 1;
            while (j > 0 && !(P[i][0] > P[j][1]))
                j--;

            dp[i] = dp[j] + 1;
        }

        return dp[n];
    }
};

// DP solution
// sort

// dp[i] -> minimum number of arrows that must be shot to burst [0:i] ballons

// dp[i] = dp[j] + 1; where j -> overlapping ballon
