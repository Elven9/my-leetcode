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
    vector<string> getWordsInLongestSubsequence(vector<string> &W, vector<int> &G)
    {
        int n = W.size();

        auto dp = vector<vector<int>>(n, vector<int>(2, 1));

        for (int i = 0; i < n; i++)
            dp[i][1] = i;

        int maxIdx = -1, maxV = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (G[i] != G[j] &&
                    W[i].size() == W[j].size() &&
                    dist(W[i], W[j]) == 1 &&
                    dp[i][0] < dp[j][0] + 1)
                {
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = j;
                }
            }
            if (dp[i][0] > maxV)
            {
                maxV = dp[i][0];
                maxIdx = i;
            }
        }

        vector<string> res;
        res.insert(res.begin(), W[maxIdx]);
        while (dp[maxIdx][1] != maxIdx)
        {
            maxIdx = dp[maxIdx][1];
            res.insert(res.begin(), W[maxIdx]);
        }

        return res;
    }

    int dist(string &a, string &b)
    {
        int d = 0;
        for (int i = 0; i < a.size(); i++)
            d += a[i] != b[i];
        return d;
    }
};
