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
    int countSquares(vector<vector<int>> &M)
    {
        int m = M.size(), n = M[0].size();
        M.insert(M.begin(), vector<int>(n, 0));
        for (int i = 0; i <= m; i++)
            M[i].insert(M[i].begin(), 0);

        int res = 0;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (M[i][j] == 0)
                    continue;

                int len = min(M[i - 1][j - 1], min(M[i - 1][j], M[i][j - 1]));
                M[i][j] += len;
                res += M[i][j];
            }

        return res;
    }
};
