#include <vector>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Queue solution
        // Two scan and multiple traversal
        // Time: O(mn), O(mn)
        queue<vector<int>> rotted;
        int m = grid.size(), n = grid[0].size();

        // Check Rotton
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    vector<int> idx{i, j};
                    rotted.push(idx);
                }
            }
        }

        // Rotting
        int time = 0;
        while (true)
        {
            int qs = rotted.size();
            vector<int> payload(2, 0);
            for (int i = 0; i < qs; i++)
            {
                int oi = rotted.front()[0], oj = rotted.front()[1];
                rotted.pop();

                if (oi - 1 >= 0 && grid[oi - 1][oj] == 1)
                {
                    // up
                    grid[oi - 1][oj] = 2;
                    payload[0] = oi - 1;
                    payload[1] = oj;
                    rotted.push(payload);
                }
                if (oj + 1 < n && grid[oi][oj + 1] == 1)
                {
                    // right
                    grid[oi][oj + 1] = 2;
                    payload[0] = oi;
                    payload[1] = oj + 1;
                    rotted.push(payload);
                }
                if (oi + 1 < m && grid[oi + 1][oj] == 1)
                {
                    // down
                    grid[oi + 1][oj] = 2;
                    payload[0] = oi + 1;
                    payload[1] = oj;
                    rotted.push(payload);
                }
                if (oj - 1 >= 0 && grid[oi][oj - 1] == 1)
                {
                    // left
                    grid[oi][oj - 1] = 2;
                    payload[0] = oi;
                    payload[1] = oj - 1;
                    rotted.push(payload);
                }
            }
            if (rotted.empty())
                break;
            time++;
        }

        // Check if there are still some fresh orange
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> payload{
        vector<int>{2, 1, 1},
        vector<int>{1, 1, 0},
        vector<int>{0, 1, 1},
    };
    sol.orangesRotting(payload);

    return 0;
}
