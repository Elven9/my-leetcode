#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        int n = A.size(), m = B.size();
        A.insert(A.begin(), -1);
        B.insert(B.begin(), -1);

        auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        int ret = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = A[i] == B[j] ? dp[i - 1][j - 1] + 1 : 0;
                ret = max(ret, dp[i][j]);
            }

        return ret;
    }
};

// dp[i][j]: maximum length of a subarray that appears in A[0:i] and B[0:j]
// 這個轉移狀態太難寫了，所以我們把 dp 改成

// dp[i][j]: common subarray that end at A[0:i] and B[0:j]'s maximum length
