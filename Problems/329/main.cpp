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

using namespace std;

class Solution
{
public:
    int dp[205][205] = {0};
    int M, N;
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        M = matrix.size();
        N = matrix[0].size();

        int ret = 1;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (dp[i][j] != 1)
                    dp[i][j] = dfs(matrix, i, j);
                ret = max(ret, dp[i][j]);
            }

        return ret;
    }

    int dfs(vector<vector<int>> &matrix, int i, int j)
    {
        if (dp[i][j] != 0)
            return dp[i][j];

        int val = matrix[i][j];
        int ret = 1;
        if (i + 1 < M && matrix[i + 1][j] > val)
            ret = max(ret, 1 + dfs(matrix, i + 1, j));
        if (i - 1 >= 0 && matrix[i - 1][j] > val)
            ret = max(ret, 1 + dfs(matrix, i - 1, j));
        if (j + 1 < N && matrix[i][j + 1] > val)
            ret = max(ret, 1 + dfs(matrix, i, j + 1));
        if (j - 1 >= 0 && matrix[i][j - 1] > val)
            ret = max(ret, 1 + dfs(matrix, i, j - 1));

        dp[i][j] = ret;
        return ret;
    }
};
