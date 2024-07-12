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
    int minimumTotal(vector<vector<int>> &tri)
    {
        int n = tri.size();
        auto dp = vector<int>(n, INT_MAX / 2);

        dp[0] = tri[0][0];
        for (int i = 1; i < n; i++)
        {
            auto dp2 = dp;
            for (int j = 0; j <= i; j++)
                dp[j] = min(dp2[max(0, j - 1)], dp2[min(i - 1, j)]) + tri[i][j];
        }

        return *min_element(dp.begin(), dp.end());
    }
};

// dp[i][j]: i row, j col, minimum path to this place
// overlapping subproblem
