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
    void rotate(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        // 1. flip on diagnoal line
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n - i; j++)
            {
                swap(matrix[i][j], matrix[m - j - 1][n - i - 1]);
            }

        // 2. flip on horizontal line
        for (int i = 0; i < m / 2; i++)
            for (int j = 0; j < n; j++)
            {
                swap(matrix[i][j], matrix[m - i - 1][j]);
            }
    }
};

// 1 2 3
// 4 5 6
// 7 8 9

// 9 6 3
// 8 5 2
// 7 4 1

// 7 4 1
// 8 5 2
// 9 6 3
