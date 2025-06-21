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
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        // constant space, 不是叫你啥都不用 = =, 被限制住想法了

        bool rowHasZero = false;
        for (auto &n : matrix[0])
            rowHasZero |= n == 0;

        bool colHasZero = false;
        for (int i = 0; i < m; i++)
            colHasZero |= matrix[i][0] == 0;

        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        // draw
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;

        if (rowHasZero)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        if (colHasZero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};

// 0 1 2 0
// 3 4 5 2
// 1 3 1 5

// if (0, 0) == 0 -> 整個 row col 都要變 0
// if (x, 0) has zero -> 整個 col 都要變 0
// if (0, xx) has zero
