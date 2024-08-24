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
    int shortestPathAllKeys(vector<string> &grid)
    {
        int M = grid.size(), N = grid[0].size();
        pair<int, int> st;

        int cnt = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '@')
                {
                    st = {i, j};
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    cnt++;
            }

        int T = (1 << cnt) - 1;

        vector<vector<int>> dir({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});

        auto visited = vector<vector<unordered_map<int, bool>>>(M, vector<unordered_map<int, bool>>(N));
        queue<pair<pair<int, int>, int>> q;

        q.push({st, 0});
        visited[st.first][st.second][0] = true;

        int step = 0;
        while (!q.empty())
        {
            int len = q.size();

            while (len--)
            {
                for (auto &d : dir)
                {
                    int m = q.front().first.first + d[0];
                    int n = q.front().first.second + d[1];
                    int state = q.front().second;
                    if (m < 0 || m >= M || n < 0 || n >= N)
                        continue;

                    char c = grid[m][n];
                    if (c == '#')
                        continue;
                    if (c >= 'A' && c <= 'F' && (state & (1 << (c - 'A'))) == 0)
                        continue;
                    if (c >= 'a' && c <= 'f')
                        state = state | (1 << (c - 'a'));

                    if (state == T)
                        return step + 1;

                    if (visited[m][n][state])
                        continue;
                    q.push({{m, n}, state});
                    visited[m][n][state] = true;
                }
                q.pop();
            }
            step++;
        }

        return -1;
    }
};

// [
//     "@...a",
//     ".###A",
//     "b.BCc"
// ]
