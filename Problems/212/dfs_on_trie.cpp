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

struct Node
{
    bool added;
    bool isEnd;
    Node *ch[26];
    Node()
    {
        added = false;
        isEnd = false;
        for (int i = 0; i < 26; i++)
            ch[i] = nullptr;
    }
};

class Solution
{
public:
    Node *root;
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<string> res;
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int m = board.size(), n = board[0].size();
        root = new Node();

        for (auto &w : words)
        {
            Node *cur = root;
            for (auto &c : w)
            {
                int idx = c - 'a';
                if (!cur->ch[idx])
                    cur->ch[idx] = new Node();
                cur = cur->ch[idx];
            }
            cur->isEnd = true;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        string cur;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (!root->ch[board[i][j] - 'a'])
                    continue;
                cur.push_back(board[i][j]);
                dfs(i, j, root->ch[board[i][j] - 'a'], cur, board, visited);
                cur.pop_back();
            }

        return res;
    }

    void dfs(int i, int j, Node *r, string &cur, vector<vector<char>> &board, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
        if (r->isEnd && !r->added)
        {
            res.push_back(cur);
            r->added = true;
        }

        int m = board.size(), n = board[0].size();
        for (auto &[di, dj] : dir)
        {
            int ni = i + di, nj = j + dj;

            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                continue;
            if (visited[ni][nj])
                continue;
            if (!r->ch[board[ni][nj] - 'a'])
                continue;

            cur.push_back(board[ni][nj]);
            dfs(ni, nj, r->ch[board[ni][nj] - 'a'], cur, board, visited);
            cur.pop_back();
        }

        visited[i][j] = false;
    }
};

// DFS on Trie
