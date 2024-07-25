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
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();

        auto dp = vector<vector<int>>(n, vector<int>(n, 0));
        auto largest = vector<vector<int>>(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            largest[i][i] = arr[i];

        for (int len = 2; len <= n; len++)
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1;

                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + largest[i][k] * largest[k + 1][j]);
                }
                largest[i][j] = max(largest[i][i], largest[i + 1][j]);
            }

        return dp[0][n - 1];
    }
};

//        X
//      X  [X]
//    X  [X]
// [X]  X
//    [X X]

//          X
// [X X X X] [X X X]
//      X          X
// [X X] [X X] [X X] [X]
