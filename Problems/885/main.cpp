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
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c)
    {
        int N = r, E = c + 1, S = r, W = c;
        int dir[2] = {0, 1};

        vector<vector<int>> res;
        while (N >= 0 || E < cols || S < rows || W >= 0)
        {
            if (r < rows && r >= 0 && c < cols && c >= 0)
                res.push_back({r, c});

            if (r + dir[0] < N || r + dir[0] > S || c + dir[1] > E || c + dir[1] < W)
            {
                // Change Boundrary
                if (dir[1] == 1)
                    S++;
                else if (dir[0] == 1)
                    W--;
                else if (dir[1] == -1)
                    N--;
                else if (dir[0] == -1)
                    E++;

                // direction change E -> S -> W -> N
                dir[0] *= -1;
                swap(dir[0], dir[1]);
            }
            r += dir[0];
            c += dir[1];
        }
        return res;
    }
};

// four direction boudary, reach and change direction

// 0 1 -> update S
// 1 0 -> update W
// 0 -1 -> update N
// -1 0 -> update E
