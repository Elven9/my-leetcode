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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> b = {0, 0, int(matrix.size()), int(matrix[0].size())};
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int dir = 0;
        int x = 0, y = 0;
        vector<int> res;
        while (x >= b[0] && x < b[2] && y >= b[1] && y < b[3])
        {
            res.push_back(matrix[x][y]);

            int nx = x + dirs[dir][0], ny = y + dirs[dir][1];
            if (nx < b[0] || nx >= b[2] || ny < b[1] || ny >= b[3])
            {
                if (dir == 0)
                    b[0]++;
                else if (dir == 1)
                    b[3]--;
                else if (dir == 2)
                    b[2]--;
                else
                    b[1]++;
                dir = (dir + 1) % 4;
                nx = x + dirs[dir][0];
                ny = y + dirs[dir][1];
            }
            x = nx;
            y = ny;
        }

        return res;
    }
};

// simulation .. ? or can I generate in some order

// 4x4
