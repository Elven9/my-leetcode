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
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        for (auto &row : matrix)
            for (auto &v : row)
                res += v;

        for (int len = 1; len < min(m, n); len++)
            for (int i = len; i < m; i++)
                for (int j = len; j < n; j++)
                {
                    if (matrix[i][j] == 0 || matrix[i][j - 1] < len || matrix[i - 1][j] < len || matrix[i - 1][j - 1] < len)
                        continue;
                    matrix[i][j] = len + 1;
                    res++;
                }

        return res;
    }
};

// gen prefix
