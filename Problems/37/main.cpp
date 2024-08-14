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
    vector<vector<char>> res;
    void solveSudoku(vector<vector<char>> &board)
    {
        dfs(board, 0);
        board = res;
    }

    void dfs(vector<vector<char>> &board, int depth)
    {
        if (depth == 81)
        {
            res = board;
            return;
        }

        int i = depth / 9, j = depth % 9;
        if (board[i][j] != '.')
            dfs(board, depth + 1);
        else
        {
            for (int n = '1'; n <= '9'; n++)
            {
                if (prune(board, i, j, n))
                    continue;

                board[i][j] = n;
                dfs(board, depth + 1);
                board[i][j] = '.';
            }
        }
    }

    bool prune(vector<vector<char>> &board, int i, int j, char val)
    {
        for (int c = 0; c < 9; c++)
            if (c != j && board[i][c] == val)
                return true;

        for (int r = 0; r < 9; r++)
            if (r != i && board[r][j] == val)
                return true;

        int m = i / 3 * 3, n = j / 3 * 3;
        for (int r = m; r < m + 3; r++)
            for (int c = n; c < n + 3; c++)
            {
                if (r == i && c == j)
                    continue;
                if (board[r][c] == val)
                    return true;
            }

        return false;
    }
};
