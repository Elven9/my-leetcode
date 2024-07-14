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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 1)
            return matrix[0][0];

        auto dp = vector<pair<int, int>>(n);

        for (int j = 0; j < n; j++)
            dp[j] = {matrix[0][j], j};

        for (int i = 1; i < n; i++)
        {
            auto dp2 = dp;
            sort(dp2.begin(), dp2.end());

            for (int j = 0; j < n; j++)
                dp[j].first = (dp2[0].second == j ? dp2[1].first : dp2[0].first) + matrix[i][j];
        }

        return (*min_element(dp.begin(), dp.end())).first;
    }
};
