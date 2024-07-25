#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        word1 = "#" + word1;
        word2 = "#" + word2;

        auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        // Need to check boundrary condition (index 0)
        for (int i = 1; i <= n; i++)
            dp[i][0] = i; // all delete

        for (int i = 1; i <= m; i++)
            dp[0][i] = i; // all insert

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    // convert word1 to word2 => only modify word1
                    //             replace          insert        delete
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));

        return dp[n][m];
    }
};

// 這其實還是狀態轉換 ww or 是說決策轉換 ( build from sub problem )
// X X X X X X X i     dp[i][j] : minimum number of operations required to convert word1[0:i] to word2[0:j]
// X X X X X X j

// convert i to j
