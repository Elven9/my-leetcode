#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        return max(rob(0, n - 2, slices, n / 3), rob(1, n - 1, slices, n / 3));
    }
    int rob(int st, int ed, vector<int> &slices, int k)
    {
        int dp0[501][501]; // take when already take j slice
        int dp1[501][501]; // not take when already take j slice
        for (int i = 0; i < 501; i++)
        {
            for (int j = 0; j < 501; j++)
            {
                dp0[i][j] = 0;
                dp1[i][j] = 0;
            }
        }
        dp0[st][1] = slices[st];
        for (int i = st + 1; i != ed + 1; i++)
        {
            for (int j = 1; j < k + 1; j++)
            {
                dp0[i][j] = dp1[i - 1][j - 1] + slices[i];
                dp1[i][j] = max(dp0[i - 1][j], dp1[i - 1][j]);
            }
        }
        return max(dp0[ed][k], dp1[ed][k]);
    }
};
