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
    vector<vector<int>> pSum;
    int maxSideLength(vector<vector<int>> &mat, int T)
    {
        int m = mat.size(), n = mat[0].size();
        pSum.resize(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                pSum[i][j] = mat[i - 1][j - 1] + pSum[i][j - 1] + pSum[i - 1][j] - pSum[i - 1][j - 1];

        int l = 0, r = min(m, n);

        while (l < r)
        {
            int mid = r - (r - l) / 2;

            if (check(mat, T, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    bool check(vector<vector<int>> &mat, int threshold, int len)
    {
        int M = mat.size(), N = mat[0].size();
        for (int i = len; i <= M; i++)
            for (int j = len; j <= N; j++)
            {
                int sum = pSum[i][j] - pSum[i][j - len] - pSum[i - len][j] + pSum[i - len][j - len];

                if (sum <= threshold)
                    return true;
            }

        return false;
    }
};
