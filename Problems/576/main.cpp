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
    long M = 1e9 + 7;
    int findPaths(int m, int n, int K, int i0, int j0)
    {
        auto dp = vector<vector<long>>(m, vector<long>(n, 0));
        for (int k = 0; k < K; k++)
        {
            auto dp2 = dp;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                {
                    long up = i == 0 ? 1 : dp2[i - 1][j];
                    long left = j == 0 ? 1 : dp2[i][j - 1];
                    long down = i == m - 1 ? 1 : dp2[i + 1][j];
                    long right = j == n - 1 ? 1 : dp2[i][j + 1];
                    dp[i][j] = (up + left + down + right) % M;
                }
        }
        return dp[i0][j0];
    }
};

// DFS, naive solution

// calculate from start pt .. ?
// dp[i][j][m], m stands for move
// dp[i][j][m] = dp[i-1][j][m-1] + dp[i][j+1][m-1] + dp[i+1][j][m-1] + dp[i][j-1][m-1];
//
// nah, m is for diffusion style update, no need to add one more layer

// too much problem, (calculate from div, first path here, repatitive calculation ... bla bla bla)
//
// calculate from each border blks !!!
// path w/ diff m steps
