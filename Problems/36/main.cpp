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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // rule 1
        for (int i = 0; i < 9; i++)
        {
            vector<bool> used(9, false);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (used[board[i][j]])
                    return false;
                used[board[i][j]] = true;
            }
        }

        // rule 2
        for (int j = 0; j < 9; j++)
        {
            vector<bool> used(9, false);
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] == '.')
                    continue;
                if (used[board[i][j]])
                    return false;
                used[board[i][j]] = true;
            }
        }

        // rule 3
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
            {
                vector<bool> used(9, false);
                for (int k = 0; k < 9; k++)
                {
                    int x = i + k / 3, y = j + k % 3;
                    if (board[x][y] == '.')
                        continue;
                    if (used[board[x][y]])
                        return false;
                    used[board[x][y]] = true;
                }
            }

        return true;
    }
};
