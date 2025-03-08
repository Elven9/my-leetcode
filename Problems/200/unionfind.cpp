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
    int m, n;
    vector<int> root;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();

        root = vector<int>(m * n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                root[i * n + j] = i * n + j;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0')
                    continue;

                for (auto &d : dirs)
                {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;
                    if (grid[ni][nj] == '0')
                        continue;

                    if (find(i, j) != find(ni, nj))
                        merge(i, j, ni, nj);
                }
            }

        set<int> Set;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0')
                    continue;
                Set.insert(find(i, j));
            }

        return Set.size();
    }

    int find(int i, int j)
    {
        int idx = i * n + j;
        if (root[idx] != idx)
            root[idx] = find(root[idx] / n, root[idx] % n);
        return root[idx];
    }

    void merge(int i, int j, int ni, int nj)
    {
        int r1 = root[i * n + j];
        int r2 = root[ni * n + nj];
        root[r1] = r2;
    }
};
