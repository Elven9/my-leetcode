#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // Naive DP solution: O(mn), O(mn)
        // Is there a O(m+n) greedy solution ?
        int m = grid.size(), n = grid[0].size();

        // First Row and Column
        for (int i = 1; i < m; i++)
            grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < n; i++)
            grid[0][i] += grid[0][i - 1];

        // DP Start
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

        return grid[m - 1][n - 1];
    }
};
