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
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();

        auto dp = vector<vector<int>>(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
            dp[i][1] = i;
        }

        int max = 1, idx = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (groups[j] != groups[i] && dp[i][0] < dp[j][0] + 1)
                {
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = j;
                }
            }
            if (dp[i][0] > max)
            {
                max = dp[i][0];
                idx = i;
            }
        }

        vector<string> res;
        while (true)
        {
            res.insert(res.begin(), words[idx]);
            if (dp[idx][1] == idx)
                break;
            idx = dp[idx][1];
        }

        return res;
    }
};

// O(n^2) DP -> Backtracking
