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
    vector<pair<int, int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int cnt = getCnt(board, i, j);
                if (board[i][j] == 0 && cnt == 3)
                    board[i][j] += 10;
                else if (board[i][j] == 1 && (cnt == 2 || cnt == 3))
                    board[i][j] += 10;
            }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = board[i][j] >= 10 ? 1 : 0;
    }
    int getCnt(vector<vector<int>> &board, int i, int j)
    {
        int m = board.size(), n = board[0].size();

        int cnt = 0;
        for (auto &dir : dirs)
        {
            int ni = i + dir.first, nj = j + dir.second;
            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                continue;
            cnt += board[ni][nj] % 10 == 1 ? 1 : 0;
        }
        return cnt;
    }
};
