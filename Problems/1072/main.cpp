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
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][0] == matrix[j][0] && matrix[i] == matrix[j])
                    cnt++;
                else
                {
                    bool ok = true;
                    for (int k = 0; k < n; k++)
                        if (matrix[i][k] == matrix[j][k])
                        {
                            ok = false;
                            break;
                        }
                    if (ok)
                        cnt++;
                }
            }
            res = max(res, cnt);
        }

        return res;
    }
};
