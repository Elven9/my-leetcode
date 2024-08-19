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
    void solve(vector<vector<char>> &board)
    {
        M = board.size();
        N = board[0].size();

        for (int i = 0; i < M; i++)
        {
            bfs(board, i, 0);
            bfs(board, i, N - 1);
        }

        for (int j = 0; j < N; j++)
        {
            bfs(board, 0, j);
            bfs(board, M - 1, j);
        }

        // construct result
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'V')
                    board[i][j] = 'O';
            }
    }

    void bfs(vector<vector<char>> &board, int i, int j)
    {
        if (board[i][j] != 'O')
            return;

        queue<pair<int, int>> q;
        board[i][j] = 'V';
        q.push({i, j});

        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            if (i - 1 >= 0 && board[i - 1][j] == 'O')
            {
                board[i - 1][j] = 'V';
                q.push({i - 1, j});
            }
            if (i + 1 < M && board[i + 1][j] == 'O')
            {
                board[i + 1][j] = 'V';
                q.push({i + 1, j});
            }
            if (j - 1 >= 0 && board[i][j - 1] == 'O')
            {
                board[i][j - 1] = 'V';
                q.push({i, j - 1});
            }
            if (j + 1 < N && board[i][j + 1] == 'O')
            {
                board[i][j + 1] = 'V';
                q.push({i, j + 1});
            }
        }
    }
};
