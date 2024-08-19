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
    int M, N;
    vector<vector<char>> updateBoard(vector<vector<char>> &B, vector<int> &C)
    {
        queue<pair<int, int>> q;
        M = B.size();
        N = B[0].size();

        int i = C[0], j = C[1];
        if (B[i][j] == 'M')
        {
            B[i][j] = 'X';
            return B;
        }

        vector<vector<bool>> inQueue(M, vector<bool>(N, false));
        vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

        q.push({i, j});
        inQueue[i][j] = true;
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            vector<pair<int, int>> tmp;
            int cnt = 0;
            for (auto &d : dirs)
            {
                int x = i + d[0], y = j + d[1];

                if (x < 0 || x >= M || y < 0 || y >= N)
                    continue;

                if (B[x][y] == 'M')
                    cnt++;
                if (B[x][y] == 'E')
                    tmp.push_back({x, y});
            }

            B[i][j] = cnt == 0 ? 'B' : '0' + cnt;

            if (B[i][j] == 'B')
                for (auto t : tmp)
                {
                    if (inQueue[t.first][t.second])
                        continue;
                    q.push(t);
                    inQueue[t.first][t.second] = true;
                }
        }
        return B;
    }
};
