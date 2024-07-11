#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size(), m = key.size();
        auto dp = vector<vector<int>>(m, vector<int>(n, INT_MAX / 2));

        unordered_map<char, vector<int>> charPos;
        for (int i = 0; i < n; i++)
            charPos[ring[i]].push_back(i);

        for (auto &i : charPos[key[0]])
            dp[0][i] = min(i, n - i);

        for (int i = 1; i < m; i++)
            for (auto &curpos : charPos[key[i]])
                for (auto &prevpos : charPos[key[i - 1]])
                    dp[i][curpos] = min(dp[i][curpos], dp[i - 1][prevpos] + min(abs(curpos - prevpos), n - abs(curpos - prevpos)));

        int ret = INT_MAX / 2;
        for (auto &i : charPos[key[m - 1]])
            ret = min(ret, dp[m - 1][i]);

        return ret + m;
    }
};
