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
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int minimumEffortPath(vector<vector<int>> &H)
    {
        int l = 0, r = INT_MAX;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(H, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    bool check(vector<vector<int>> &H, int diff)
    {
        int m = H.size(), n = H[0].size();
        auto visited = vector<vector<bool>>(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push({m - 1, n - 1});
        visited[m - 1][n - 1] = true;

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            if (i == 0 && j == 0)
                return true;
            for (auto &d : dir)
            {
                int ni = i + d.first, nj = j + d.second;
                if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                    continue;
                if (visited[ni][nj])
                    continue;
                if (abs(H[i][j] - H[ni][nj]) > diff)
                    continue;
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
        return false;
    }
};
