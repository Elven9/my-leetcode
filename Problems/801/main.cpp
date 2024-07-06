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
    int minSwap(vector<int> &A, vector<int> &B)
    {
        int inf = 1e5 + 1;
        int n = A.size();
        vector<int> dp(2, 0); // dp[0] -> changed, [1] -> not changed
        dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            vector<int> old = dp;
            dp[0] = 1 + min(
                            B[i] > B[i - 1] && A[i] > A[i - 1] ? old[0] : inf,
                            B[i] > A[i - 1] && A[i] > B[i - 1] ? old[1] : inf);
            dp[1] = min(
                A[i] > B[i - 1] && B[i] > A[i - 1] ? old[0] : inf,
                A[i] > A[i - 1] && B[i] > B[i - 1] ? old[1] : inf);
        }
        return *min_element(dp.begin(), dp.end());
    }
};

// previous one has swap or not
