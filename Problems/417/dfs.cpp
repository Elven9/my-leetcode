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
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &H)
    {
        int m = H.size(), n = H[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            dfs(H, i, 0, pac);
        for (int i = 0; i < m; i++)
            dfs(H, i, n - 1, atl);
        for (int j = 0; j < n; j++)
            dfs(H, 0, j, pac);
        for (int j = 0; j < n; j++)
            dfs(H, m - 1, j, atl);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});

        return res;
    }

    void dfs(vector<vector<int>> &H, int i, int j, vector<vector<bool>> &reach)
    {
        reach[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int m = i + dir[k][0], n = j + dir[k][1];
            if (m < 0 || m >= H.size() || n < 0 || n >= H[0].size())
                continue;
            if (reach[m][n])
                continue;
            if (H[m][n] < H[i][j])
                continue;

            dfs(H, m, n, reach);
        }
    }
};
