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
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<string> res;
        for (auto &w : words)
        {
            bool ok = false;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (dfs(w, 0, i, j, board, visited))
                    {
                        ok = true;
                        break;
                    }
            if (ok)
                res.push_back(w);
        }
        return res;
    }

    bool dfs(string &s, int st, int i, int j, vector<vector<char>> &board, vector<vector<bool>> &visited)
    {
        if (board[i][j] != s[st])
            return false;
        if (st == s.size() - 1)
            return true;
        visited[i][j] = true;

        int m = board.size(), n = board[0].size();
        bool ok = false;
        for (auto &[di, dj] : dir)
        {
            int ni = i + di, nj = j + dj;

            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                continue;
            if (visited[ni][nj])
                continue;
            ok = dfs(s, st + 1, ni, nj, board, visited);
            if (ok)
                break;
        }

        visited[i][j] = false;
        return ok;
    }
};

// DFS
