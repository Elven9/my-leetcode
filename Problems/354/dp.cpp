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

using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &E)
    {
        sort(E.begin(), E.end(), [&](vector<int> &a, vector<int> &b) -> bool
             {
            if (a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0]; });

        int n = E.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                dp[i] = max(dp[i], E[j][0] < E[i][0] && E[j][1] < E[i][1] ? dp[j] + 1 : INT_MIN);

        return *max_element(dp.begin(), dp.end());
    }
};

// O(n^2) dp solution, it's gonna TLE ww
