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
    int minimumOperations(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        auto freq = vector<vector<int>>(m + 1, vector<int>(10, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                freq[j + 1][grid[i][j]]++;

        auto dp = vector<vector<int>>(m + 1, vector<int>(10, 0));

        for (int i = 1; i <= m; i++)
            for (int j = 0; j < 10; j++)
            {
                int res = INT_MAX;
                for (int k = 0; k < 10; k++)
                {
                    if (k == j)
                        continue;
                    res = min(res, dp[i - 1][k] + (n - freq[i][j]));
                }
                dp[i][j] = res;
            }

        int res = INT_MAX;
        for (int i = 0; i < 10; i++)
            res = min(res, dp[m][i]);
        return res;
    }
};

// Simple Solution Recursive Check
