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
    int maxKilledEnemies(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        auto kill = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'E')
                    cnt++;
                else if (grid[i][j] == 'W')
                    cnt = 0;
                kill[i][j] += cnt;
            }

            cnt = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 'E')
                    cnt++;
                else if (grid[i][j] == 'W')
                    cnt = 0;
                kill[i][j] += cnt;
            }
        }

        for (int j = 0; j < n; j++)
        {
            int cnt = 0;
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j] == 'E')
                    cnt++;
                else if (grid[i][j] == 'W')
                    cnt = 0;
                kill[i][j] += cnt;
            }

            cnt = 0;
            for (int i = m - 1; i >= 0; i--)
            {
                if (grid[i][j] == 'E')
                    cnt++;
                else if (grid[i][j] == 'W')
                    cnt = 0;
                kill[i][j] += cnt;
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res = max(res, grid[i][j] == '0' ? kill[i][j] : INT_MIN);

        return res;
    }
};

// O(mn), O(mn)

// Scan O(mn) again to get maximum
